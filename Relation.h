#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

#define ERR_ATTRIBUTE_INDEX_NOT_FOUND		101
#define ERR_ATTRIBUTE_TYPE_NOT_FOUND		"NO_TYPE"
#define ERR_COLUMN_NOT_FOUND				"NO_COLUMN"
#define ERR_ROW_NOT_FOUND					"NO_ROW"

using namespace std;

class AttributeProperties{
	public:
		string type;
		int index;
};
class Schema{
	private:
		unordered_map<string, AttributeProperties> _schema;
	public:
		void setSchema(string firstRow);
		unordered_map<string, AttributeProperties> getSchema();
		int getCorrespondingIndex(string attributeName);
		string getTypeOfAttribute(string attributeName);
		int getNumberOfAttributes();
		void insertIntoSchema(string attributeName, string attributeType, int indexOfEntry);
		void insertIntoSchema(string attributeName, string attributeType);
		void insertIntoSchema(string attributeName, AttributeProperties attributeProperties);
		void printSchema();
		
		static bool operator ==(const Schema& a, const Schema& b);
        static bool operator !=(const Schema& a, const Schema& b);
		
};
class Record{
	private:
		vector<string> _record;
		
	public:
		Record(Record r1, Record r2);
		vector<string> getRecord();
		void setRecord(string rowValue);
		string getColumnValue(int index);
		string getColumnValue(string attributeName);	//TO DO: HOW TO USE Schema in the Record Class
		void printRecord();
		
		static bool Record::operator ==(const Schema& a, const Schema& b);
		static bool Record::operator !=(const Schema& a, const Schema& b);
		
};

class Relation{
	public:
		string tableName;
		Schema schema;
		vector<Record> records;
		
		Relation();
		Relation(string filename);
		Relation(Schema s);
		Record fetchRecord(int index);
		void insertRecord(string rowValue);
		void insertSchema(Schema s);
		void insertSchema(Schema s1, Schema s2);
		
		string getEntry(int rowIndex, string attributeName);
		int contains(Record r);
		
		void printRelation();
		
};
