from libsal import *

s1 = [[1,2],[2,3],[3,4],[4,5]]
s2 = s1
m1 = Matrix(s1)
m2 = Matrix(s2)

print m1
print m2

am = AuthorizationManager("dtw.cfg")
print am.registry(1, m1, m2)

print "Done success!"
