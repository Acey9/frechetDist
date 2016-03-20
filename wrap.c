#include <Python.h>
#include "frechet.h"

PyObject* wrap_distance(PyObject* self, PyObject* args)
{
    int n, m, idx;
    double dist, x, y;
    __point *P = NULL, *Q=NULL;

    PyObject *pl=NULL, *ql=NULL, *item=NULL;

    if (! PyArg_ParseTuple(args, "iiOO", &m, &n, &pl, &ql)) {
        Py_RETURN_NONE;
        }

    if (!PyList_Check(pl)) {
        Py_RETURN_NONE;
        }

    if(!PyList_Check(ql)) {
        Py_RETURN_NONE;
        }

    P=malloc(m*sizeof(__point));
    Q=malloc(n*sizeof(__point));

    for (idx=0; idx<m; idx++) {
        item = PyList_GetItem(pl, idx);
        x = PyFloat_AsDouble(PyList_GetItem(item, 0));
        y = PyFloat_AsDouble(PyList_GetItem(item, 1));
        P[idx].x = x;
        P[idx].y = y;
        }
    for (idx=0; idx<n; idx++) {
        item = PyList_GetItem(ql, idx);
        x = PyFloat_AsDouble(PyList_GetItem(item, 0));
        y = PyFloat_AsDouble(PyList_GetItem(item, 1));
        Q[idx].x = x;
        Q[idx].y = y;
        }

    dist = distance(m, n, P, Q);

    Py_DECREF(pl);
    Py_DECREF(ql);
    Py_DECREF(P);
    Py_DECREF(Q);
    //pl = ql = NULL;
    //P = Q = NULL;

    return Py_BuildValue("f", dist);
}

static PyMethodDef frechetMethods[] =
{
    {"distance", wrap_distance, METH_VARARGS, "frechet distance."},
    {NULL, NULL, 0, NULL}
};

void initfrechet()
{
    PyObject* m;
    m = Py_InitModule("frechet", frechetMethods);
}
