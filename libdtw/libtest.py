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

s = Signature(p)
print ("Save signature to database...")
ds.saveSignature(1, s)

print ("Load signature from database...")
ds.loadSignature(1)

print ("Done!")