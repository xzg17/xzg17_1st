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


static PyMethodDef myMethods[] = {
    {"mypow", mypowWrapper, METH_VARARGS, NULL},
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
