#include "../MongoDbDataSource.h"
#include "../Signature.h"
#include "../Configuration.h"

#include <vector>
#include <iostream>

#include <mongo/client/dbclient.h>

using namespace std;

using namespace SignatureAuthLibrary;


int main(int argc, char** argv)
{
    if (argc > 1) 
    {
	cout << "Configuration..." << endl;
	Configuration cfg = Configuration(argv[1]);

	cout << "Connect to db..." << endl;
	DataSource* ds = new MongoDbDataSource(cfg);
	ds->connect();

 	cout << "Generate sign..." << endl;
	vector<Point> points;
	points.push_back(Point(1,2));
	points.push_back(Point(2,3));
	points.push_back(Point(3,4));
	points.push_back(Point(4,5));

	Signature s(points);

	cout << "Save to database..." << endl;
	ds->saveSignature(2, s);

	cout << "Load from database..." << endl;
	Signature s1 = ds->loadSignature(2);

	assert(s1 == s);

	cout << "Done!" << endl;
    }
}
