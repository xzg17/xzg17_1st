#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "pow.h"

static PyObject *
mypowWrapper(PyObject *self, PyObject *args) {

    int x, y, d;

    if (!PyArg_ParseTuple(args, "iii", &x, &y, &d)) {
        return NULL;
    }

    int z = mypow(x, y, d);

    return Py_BuildValue("i", z);
}


static PyMethodDef myMethods[] = {
    {"MyPow", mypowWrapper, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "xzg17",
    NULL,
    -1,
    myMethods
};

PyMODINIT_FUNC
PyInit_MyCalc(void) {
    return PyModule_Create(&myModule);
}
