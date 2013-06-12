from libsal import *
import os
def test():
    os.system("mongo sal --eval 'db.users.drop()'") 
    s1 = [[1,2],[2,3],[3,4],[4,5]]
    s2 = [[1,2],[2,3],[2,3],[3,4],[4,5]]
    m1 = Matrix(s1)
    m2 = Matrix(s2)

    am = AuthorizationManager("dtw.cfg")

    registryCode = am.registry(1, m1, m2)
    print "Registry code %i" % registryCode
    if (registryCode != 1):
        print "Test failed!"
    	return

    authorizeCode = am.authorize(1, m1);
    print "Authorize code %i" % authorizeCode
    if (authorizeCode != 1):
        print "Test failed!"
        return


    print "Test success!"


def test2():
    os.system("mongo sal --eval 'db.users.drop()'") 
    s1 = [[100,200],[150,350],[200,500],[300,470],[400,480],[450,600],[500,600],[600,400]]
    s2 = [[10,200], [110,450],[210,350],[260,400],[260,550],[310,550],[610,310]]
    m1 = Matrix(s1)
    m2 = Matrix(s2)

    am = AuthorizationManager("dtw.cfg")

    registryCode = am.registry(2, m1, m2)
    print "Registry code %i" % registryCode
    if (registryCode != 1):
        print "Test failed!"
	return    

    authorizeCode = am.authorize(2, m1);
    print "Authorize code %i" % authorizeCode
    if (authorizeCode != 1):
        print "Test failed!"
        return


    print "Test success!"


if __name__ == "__main__":
    print "------------------------TEST 1---------------------------"
    test()
    print "------------------------TEST 2---------------------------"
    test2()
