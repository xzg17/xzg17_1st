#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "func.h"

static PyObject *mypowWrapper(PyObject *self, PyObject *args){

    int x, y, d;

    if (!PyArg_ParseTuple(args, "iii", &x, &y, &d)) {
        return NULL;
    }

    int z = mypow(x, y, d)+1;

    return Py_BuildValue("i", z);
}


static PyObject *myswapWrapper(PyObject *self, PyObject *args){

    int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    
    PyObject *list = PyList_New(2);
    
    PyList_SET_ITEM(list, 0, PyLong_FromLong((long)b));
    PyList_SET_ITEM(list, 1, PyLong_FromLong((long)a));

    return list;
}

static PyMethodDef myMethods[] = {
    {"mypow", mypowWrapper, METH_VARARGS, NULL},
    {"myswap", myswapWrapper, METH_VARARGS, NULL},
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
