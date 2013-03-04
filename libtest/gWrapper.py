from ctypes import cdll
lib = cdll.LoadLibrary('./libg.so')

class G(object):
    def __init__(self):
        self.obj = lib.G_new()

    def finalize(self):
        lib.G_delete(self.obj)

    def doAction(self):
        lib.G_doAction(self.obj)

g = G()
g.doAction()
g.finalize()
#g.doAction() undefinded behaviour (work because pointer dont use)
