# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.8
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.



from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_libsal', [dirname(__file__)])
        except ImportError:
            import _libsal
            return _libsal
        if fp is not None:
            try:
                _mod = imp.load_module('_libsal', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _libsal = swig_import_helper()
    del swig_import_helper
else:
    import _libsal
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


class SwigPyIterator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SwigPyIterator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SwigPyIterator, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _libsal.delete_SwigPyIterator
    __del__ = lambda self : None;
    def value(self): return _libsal.SwigPyIterator_value(self)
    def incr(self, n=1): return _libsal.SwigPyIterator_incr(self, n)
    def decr(self, n=1): return _libsal.SwigPyIterator_decr(self, n)
    def distance(self, *args): return _libsal.SwigPyIterator_distance(self, *args)
    def equal(self, *args): return _libsal.SwigPyIterator_equal(self, *args)
    def copy(self): return _libsal.SwigPyIterator_copy(self)
    def next(self): return _libsal.SwigPyIterator_next(self)
    def __next__(self): return _libsal.SwigPyIterator___next__(self)
    def previous(self): return _libsal.SwigPyIterator_previous(self)
    def advance(self, *args): return _libsal.SwigPyIterator_advance(self, *args)
    def __eq__(self, *args): return _libsal.SwigPyIterator___eq__(self, *args)
    def __ne__(self, *args): return _libsal.SwigPyIterator___ne__(self, *args)
    def __iadd__(self, *args): return _libsal.SwigPyIterator___iadd__(self, *args)
    def __isub__(self, *args): return _libsal.SwigPyIterator___isub__(self, *args)
    def __add__(self, *args): return _libsal.SwigPyIterator___add__(self, *args)
    def __sub__(self, *args): return _libsal.SwigPyIterator___sub__(self, *args)
    def __iter__(self): return self
SwigPyIterator_swigregister = _libsal.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)

class AuthorizationManager(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AuthorizationManager, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AuthorizationManager, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libsal.new_AuthorizationManager(*args)
        try: self.this.append(this)
        except: self.this = this
    def registry(self, *args): return _libsal.AuthorizationManager_registry(self, *args)
    def authorize(self, *args): return _libsal.AuthorizationManager_authorize(self, *args)
    def delete_user(self, *args): return _libsal.AuthorizationManager_delete_user(self, *args)
    def add_sign(self, *args): return _libsal.AuthorizationManager_add_sign(self, *args)
    __swig_destroy__ = _libsal.delete_AuthorizationManager
    __del__ = lambda self : None;
AuthorizationManager_swigregister = _libsal.AuthorizationManager_swigregister
AuthorizationManager_swigregister(AuthorizationManager)

class Vector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Vector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Vector, name)
    __repr__ = _swig_repr
    def iterator(self): return _libsal.Vector_iterator(self)
    def __iter__(self): return self.iterator()
    def __nonzero__(self): return _libsal.Vector___nonzero__(self)
    def __bool__(self): return _libsal.Vector___bool__(self)
    def __len__(self): return _libsal.Vector___len__(self)
    def pop(self): return _libsal.Vector_pop(self)
    def __getslice__(self, *args): return _libsal.Vector___getslice__(self, *args)
    def __setslice__(self, *args): return _libsal.Vector___setslice__(self, *args)
    def __delslice__(self, *args): return _libsal.Vector___delslice__(self, *args)
    def __delitem__(self, *args): return _libsal.Vector___delitem__(self, *args)
    def __getitem__(self, *args): return _libsal.Vector___getitem__(self, *args)
    def __setitem__(self, *args): return _libsal.Vector___setitem__(self, *args)
    def append(self, *args): return _libsal.Vector_append(self, *args)
    def empty(self): return _libsal.Vector_empty(self)
    def size(self): return _libsal.Vector_size(self)
    def clear(self): return _libsal.Vector_clear(self)
    def swap(self, *args): return _libsal.Vector_swap(self, *args)
    def get_allocator(self): return _libsal.Vector_get_allocator(self)
    def begin(self): return _libsal.Vector_begin(self)
    def end(self): return _libsal.Vector_end(self)
    def rbegin(self): return _libsal.Vector_rbegin(self)
    def rend(self): return _libsal.Vector_rend(self)
    def pop_back(self): return _libsal.Vector_pop_back(self)
    def erase(self, *args): return _libsal.Vector_erase(self, *args)
    def __init__(self, *args): 
        this = _libsal.new_Vector(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(self, *args): return _libsal.Vector_push_back(self, *args)
    def front(self): return _libsal.Vector_front(self)
    def back(self): return _libsal.Vector_back(self)
    def assign(self, *args): return _libsal.Vector_assign(self, *args)
    def resize(self, *args): return _libsal.Vector_resize(self, *args)
    def insert(self, *args): return _libsal.Vector_insert(self, *args)
    def reserve(self, *args): return _libsal.Vector_reserve(self, *args)
    def capacity(self): return _libsal.Vector_capacity(self)
    __swig_destroy__ = _libsal.delete_Vector
    __del__ = lambda self : None;
Vector_swigregister = _libsal.Vector_swigregister
Vector_swigregister(Vector)

class Matrix(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Matrix, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Matrix, name)
    __repr__ = _swig_repr
    def iterator(self): return _libsal.Matrix_iterator(self)
    def __iter__(self): return self.iterator()
    def __nonzero__(self): return _libsal.Matrix___nonzero__(self)
    def __bool__(self): return _libsal.Matrix___bool__(self)
    def __len__(self): return _libsal.Matrix___len__(self)
    def pop(self): return _libsal.Matrix_pop(self)
    def __getslice__(self, *args): return _libsal.Matrix___getslice__(self, *args)
    def __setslice__(self, *args): return _libsal.Matrix___setslice__(self, *args)
    def __delslice__(self, *args): return _libsal.Matrix___delslice__(self, *args)
    def __delitem__(self, *args): return _libsal.Matrix___delitem__(self, *args)
    def __getitem__(self, *args): return _libsal.Matrix___getitem__(self, *args)
    def __setitem__(self, *args): return _libsal.Matrix___setitem__(self, *args)
    def append(self, *args): return _libsal.Matrix_append(self, *args)
    def empty(self): return _libsal.Matrix_empty(self)
    def size(self): return _libsal.Matrix_size(self)
    def clear(self): return _libsal.Matrix_clear(self)
    def swap(self, *args): return _libsal.Matrix_swap(self, *args)
    def get_allocator(self): return _libsal.Matrix_get_allocator(self)
    def begin(self): return _libsal.Matrix_begin(self)
    def end(self): return _libsal.Matrix_end(self)
    def rbegin(self): return _libsal.Matrix_rbegin(self)
    def rend(self): return _libsal.Matrix_rend(self)
    def pop_back(self): return _libsal.Matrix_pop_back(self)
    def erase(self, *args): return _libsal.Matrix_erase(self, *args)
    def __init__(self, *args): 
        this = _libsal.new_Matrix(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(self, *args): return _libsal.Matrix_push_back(self, *args)
    def front(self): return _libsal.Matrix_front(self)
    def back(self): return _libsal.Matrix_back(self)
    def assign(self, *args): return _libsal.Matrix_assign(self, *args)
    def resize(self, *args): return _libsal.Matrix_resize(self, *args)
    def insert(self, *args): return _libsal.Matrix_insert(self, *args)
    def reserve(self, *args): return _libsal.Matrix_reserve(self, *args)
    def capacity(self): return _libsal.Matrix_capacity(self)
    __swig_destroy__ = _libsal.delete_Matrix
    __del__ = lambda self : None;
Matrix_swigregister = _libsal.Matrix_swigregister
Matrix_swigregister(Matrix)

# This file is compatible with both classic and new-style classes.


