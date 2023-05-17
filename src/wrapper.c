#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "func.h"

static PyObject *mypowWrapper(PyObject *self, PyObject *args){

    int x, y, d;

    if (!PyArg_ParseTuple(args, "iii", &x, &y, &d)) {
        return NULL;
    }

    int z = mypow(x, y, d);

    return Py_BuildValue("i", z);
}


static PyObject *myswap(PyObject *self, PyObject *args){

    int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    
    PyObject *list = PyList_New(2);
    
    PyList_SET_ITEM(list, 1, PyInt_FromLong(a));
    PyList_SET_ITEM(list, 0, PyInt_FromLong(b));

    return list;
}

static PyMethodDef myMethods[] = {
    {"mypow", mypowWrapper, METH_VARARGS, NULL},
    {"myswap", myswap, METH_VARARGS, NULL},
    {NULL}
};

static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "xzg17",
    NULL,
    -1,
    myMethods
};

PyMODINIT_FUNC
PyInit_xzg17(void) {
    return PyModule_Create(&myModule);
}
