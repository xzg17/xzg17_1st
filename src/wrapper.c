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

    int N;

    if (!PyArg_ParseTuple(args, "i", &N)) {
        return NULL;
    }

    int primes[N];
    int pi = 0;
    int lpf[N+1];
    for(int i=0;i<N+1;i++){
        lpf[i]=0;
    }
    for(int d=2;d<N+1;d++){
        if(lpf[d]==0){
            lpf[d]=d;
            primes[pi++]=d;
        }
        for(int p=0;p<pi;p++){
            if((primes[p]*d > N)||(primes[p] > lpf[d])){
                break;
            }
            lpf[primes[p]*d] = primes[p];
        }
    }
    int prime_list[pi];
    char items[pi+2];
    items[0] = "[";
    items[pi+1] = "]";
    
    for(int i=0;i<pi;i++){
        prime_list[i]=primes[i];
        items[i] = "i";
    }

    return Py_BuildValue(items, prime_list);
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
