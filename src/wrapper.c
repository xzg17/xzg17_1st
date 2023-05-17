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


static PyObject *mysieve(PyObject *self, PyObject *args){

    long N;

    if (!PyArg_ParseTuple(args, "l", &N)) {
        return NULL;
    }

    long primes[N];
    long pi = 0;
    long lpf[N+1];
    for(long i=0;i<N+1;i++){
        lpf[i]=0;
    }
    for(long d=2;d<N+1;d++){
        if(lpf[d]==0){
            lpf[d]=d;
            primes[pi++]=d;
        }
        for(long p=0;p<pi;p++){
            if((primes[p]*d > N)||(primes[p] > lpf[d])){
                break;
            }
            lpf[primes[p]*d] = primes[p];
        }
    }
    
    PyObject *prime_list = PyList_New(pi);
    
    for(long i=0;i<pi;i++){
        PyList_SET_ITEM(prime_list, i, PyInt_FromLong(primes[i]));
    }

    return prime_list;
}

static PyMethodDef myMethods[] = {
    {"mypow", mypowWrapper, METH_VARARGS, NULL},
    {"mysieve", mysieve, METH_VARARGS, NULL},
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
