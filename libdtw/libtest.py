from libsal import *

print ("Configuration...")
cfg = Configuration("mongo.cfg") 

print ("Connect to database...")
ds = MongoDbDataSource(cfg)
ds.connect()

print ("Create signature...")
p = Points()
p.push_back(Point(1,2))
p.push_back(Point(2,3))
p.push_back(Point(3,4))
p.push_back(Point(4,5))

s1 = Signature(p)
print ("Save signature to database...")
ds.saveSignature(1, s1)

print ("Load signature from database...")
s2 = ds.loadSignature(1)

assert(s2 is None)
assert(s1 != s2)

print ("Done!")