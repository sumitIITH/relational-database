#include "RAOp.h"
#include Relation.h
RAOp::RAOp()
{
    virtual Relation evaluate()=0;
}

class UnaryRAOp: RAOp{
}

class BinaryRAOp: RAOp{
}

class Select : UnaryRAOp{

}
class Union : BinaryRAOp{
    Relation evaluate (Relation r1, Relation r2) {
        if(r1.schema != r2.schema) {
            return ;
        } else {
            vector<Record> r2Records = r2.records;

            for(int i = 0; i < r2Records.size(); i++) {
                if( !(r1.contains(r2Records[i])) ) {
                   r1.records.push_back(r2Records[i]);
                }
            }
        }
    }
}
class SetDifference : BinaryRAOp{
    Relation evaluate (Relation r1, Relation r2) {
        if(r1.schema != r2.schema) {
            return ;
        } else {
            vector<Record> r2Records = r2.records;

            for(int i = 0; i < r2Records.size(); i++) {
                if(int index = r1.contains(r2Records[i])) {
                   r1.records.erase(r1.records.begin() + index);
                }
            }
        }
    }
}
class Product : BinaryRAOp{
    Relation evaluate (Relation r1, Relation r2) {

        Relation newRelation;
        newRelation.schema.insertSchema(r1.schema, r2.schema);

        vector<Record> r1Records = r1.records;
        vector<Record> r2Records = r2.records;
        vector<Record> newRelationRecords;

        for(int i = 0; i < r1Records.size(); i++) {
            for(int j = 0; j < r2Records.size(); j++) {
                Record newRecord(r1Records[i], r2Records[j]);
                newRelationRecords.push_back(newRecord);
            }
        }

        newRelation.records = newRelationRecords;
    }
}
