//
// Generated file, do not edit! Created by nedtool 5.2 from DataPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "DataPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(DataPacket)

DataPacket::DataPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->srcNode = 0;
    this->dstNode = 0;
    this->ttl = 0;
    this->lastRouter = 0;
    this->l2 = 0;
    this->l3 = 0;
    this->l4 = 0;
    this->lastQueue = 0;
    this->q2 = 0;
    this->q3 = 0;
    this->q4 = 0;
    this->q5 = 0;
    this->lastTS = 0;
    this->t2 = 0;
    this->t3 = 0;
    this->t4 = 0;
    this->t5 = 0;
    this->routing = 0;
}

DataPacket::DataPacket(const DataPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

DataPacket::~DataPacket()
{
}

DataPacket& DataPacket::operator=(const DataPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DataPacket::copy(const DataPacket& other)
{
    this->srcNode = other.srcNode;
    this->dstNode = other.dstNode;
    this->ttl = other.ttl;
    this->lastRouter = other.lastRouter;
    this->l2 = other.l2;
    this->l3 = other.l3;
    this->l4 = other.l4;
    this->lastQueue = other.lastQueue;
    this->q2 = other.q2;
    this->q3 = other.q3;
    this->q4 = other.q4;
    this->q5 = other.q5;
    this->lastTS = other.lastTS;
    this->t2 = other.t2;
    this->t3 = other.t3;
    this->t4 = other.t4;
    this->t5 = other.t5;
    this->routing = other.routing;
}

void DataPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcNode);
    doParsimPacking(b,this->dstNode);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->lastRouter);
    doParsimPacking(b,this->l2);
    doParsimPacking(b,this->l3);
    doParsimPacking(b,this->l4);
    doParsimPacking(b,this->lastQueue);
    doParsimPacking(b,this->q2);
    doParsimPacking(b,this->q3);
    doParsimPacking(b,this->q4);
    doParsimPacking(b,this->q5);
    doParsimPacking(b,this->lastTS);
    doParsimPacking(b,this->t2);
    doParsimPacking(b,this->t3);
    doParsimPacking(b,this->t4);
    doParsimPacking(b,this->t5);
    doParsimPacking(b,this->routing);
}

void DataPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcNode);
    doParsimUnpacking(b,this->dstNode);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->lastRouter);
    doParsimUnpacking(b,this->l2);
    doParsimUnpacking(b,this->l3);
    doParsimUnpacking(b,this->l4);
    doParsimUnpacking(b,this->lastQueue);
    doParsimUnpacking(b,this->q2);
    doParsimUnpacking(b,this->q3);
    doParsimUnpacking(b,this->q4);
    doParsimUnpacking(b,this->q5);
    doParsimUnpacking(b,this->lastTS);
    doParsimUnpacking(b,this->t2);
    doParsimUnpacking(b,this->t3);
    doParsimUnpacking(b,this->t4);
    doParsimUnpacking(b,this->t5);
    doParsimUnpacking(b,this->routing);
}

int DataPacket::getSrcNode() const
{
    return this->srcNode;
}

void DataPacket::setSrcNode(int srcNode)
{
    this->srcNode = srcNode;
}

int DataPacket::getDstNode() const
{
    return this->dstNode;
}

void DataPacket::setDstNode(int dstNode)
{
    this->dstNode = dstNode;
}

int DataPacket::getTtl() const
{
    return this->ttl;
}

void DataPacket::setTtl(int ttl)
{
    this->ttl = ttl;
}

int DataPacket::getLastRouter() const
{
    return this->lastRouter;
}

void DataPacket::setLastRouter(int lastRouter)
{
    this->lastRouter = lastRouter;
}

int DataPacket::getL2() const
{
    return this->l2;
}

void DataPacket::setL2(int l2)
{
    this->l2 = l2;
}

int DataPacket::getL3() const
{
    return this->l3;
}

void DataPacket::setL3(int l3)
{
    this->l3 = l3;
}

int DataPacket::getL4() const
{
    return this->l4;
}

void DataPacket::setL4(int l4)
{
    this->l4 = l4;
}

int DataPacket::getLastQueue() const
{
    return this->lastQueue;
}

void DataPacket::setLastQueue(int lastQueue)
{
    this->lastQueue = lastQueue;
}

int DataPacket::getQ2() const
{
    return this->q2;
}

void DataPacket::setQ2(int q2)
{
    this->q2 = q2;
}

int DataPacket::getQ3() const
{
    return this->q3;
}

void DataPacket::setQ3(int q3)
{
    this->q3 = q3;
}

int DataPacket::getQ4() const
{
    return this->q4;
}

void DataPacket::setQ4(int q4)
{
    this->q4 = q4;
}

int DataPacket::getQ5() const
{
    return this->q5;
}

void DataPacket::setQ5(int q5)
{
    this->q5 = q5;
}

double DataPacket::getLastTS() const
{
    return this->lastTS;
}

void DataPacket::setLastTS(double lastTS)
{
    this->lastTS = lastTS;
}

double DataPacket::getT2() const
{
    return this->t2;
}

void DataPacket::setT2(double t2)
{
    this->t2 = t2;
}

double DataPacket::getT3() const
{
    return this->t3;
}

void DataPacket::setT3(double t3)
{
    this->t3 = t3;
}

double DataPacket::getT4() const
{
    return this->t4;
}

void DataPacket::setT4(double t4)
{
    this->t4 = t4;
}

double DataPacket::getT5() const
{
    return this->t5;
}

void DataPacket::setT5(double t5)
{
    this->t5 = t5;
}

int DataPacket::getRouting() const
{
    return this->routing;
}

void DataPacket::setRouting(int routing)
{
    this->routing = routing;
}

class DataPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DataPacketDescriptor();
    virtual ~DataPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(DataPacketDescriptor)

DataPacketDescriptor::DataPacketDescriptor() : omnetpp::cClassDescriptor("DataPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

DataPacketDescriptor::~DataPacketDescriptor()
{
    delete[] propertynames;
}

bool DataPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataPacket *>(obj)!=nullptr;
}

const char **DataPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DataPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DataPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 18+basedesc->getFieldCount() : 18;
}

unsigned int DataPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<18) ? fieldTypeFlags[field] : 0;
}

const char *DataPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcNode",
        "dstNode",
        "ttl",
        "lastRouter",
        "l2",
        "l3",
        "l4",
        "lastQueue",
        "q2",
        "q3",
        "q4",
        "q5",
        "lastTS",
        "t2",
        "t3",
        "t4",
        "t5",
        "routing",
    };
    return (field>=0 && field<18) ? fieldNames[field] : nullptr;
}

int DataPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNode")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstNode")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "ttl")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastRouter")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "l2")==0) return base+4;
    if (fieldName[0]=='l' && strcmp(fieldName, "l3")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "l4")==0) return base+6;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastQueue")==0) return base+7;
    if (fieldName[0]=='q' && strcmp(fieldName, "q2")==0) return base+8;
    if (fieldName[0]=='q' && strcmp(fieldName, "q3")==0) return base+9;
    if (fieldName[0]=='q' && strcmp(fieldName, "q4")==0) return base+10;
    if (fieldName[0]=='q' && strcmp(fieldName, "q5")==0) return base+11;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastTS")==0) return base+12;
    if (fieldName[0]=='t' && strcmp(fieldName, "t2")==0) return base+13;
    if (fieldName[0]=='t' && strcmp(fieldName, "t3")==0) return base+14;
    if (fieldName[0]=='t' && strcmp(fieldName, "t4")==0) return base+15;
    if (fieldName[0]=='t' && strcmp(fieldName, "t5")==0) return base+16;
    if (fieldName[0]=='r' && strcmp(fieldName, "routing")==0) return base+17;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DataPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "double",
        "double",
        "double",
        "double",
        "double",
        "int",
    };
    return (field>=0 && field<18) ? fieldTypeStrings[field] : nullptr;
}

const char **DataPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DataPacket *pp = (DataPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DataPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DataPacket *pp = (DataPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DataPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DataPacket *pp = (DataPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNode());
        case 1: return long2string(pp->getDstNode());
        case 2: return long2string(pp->getTtl());
        case 3: return long2string(pp->getLastRouter());
        case 4: return long2string(pp->getL2());
        case 5: return long2string(pp->getL3());
        case 6: return long2string(pp->getL4());
        case 7: return long2string(pp->getLastQueue());
        case 8: return long2string(pp->getQ2());
        case 9: return long2string(pp->getQ3());
        case 10: return long2string(pp->getQ4());
        case 11: return long2string(pp->getQ5());
        case 12: return double2string(pp->getLastTS());
        case 13: return double2string(pp->getT2());
        case 14: return double2string(pp->getT3());
        case 15: return double2string(pp->getT4());
        case 16: return double2string(pp->getT5());
        case 17: return long2string(pp->getRouting());
        default: return "";
    }
}

bool DataPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DataPacket *pp = (DataPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNode(string2long(value)); return true;
        case 1: pp->setDstNode(string2long(value)); return true;
        case 2: pp->setTtl(string2long(value)); return true;
        case 3: pp->setLastRouter(string2long(value)); return true;
        case 4: pp->setL2(string2long(value)); return true;
        case 5: pp->setL3(string2long(value)); return true;
        case 6: pp->setL4(string2long(value)); return true;
        case 7: pp->setLastQueue(string2long(value)); return true;
        case 8: pp->setQ2(string2long(value)); return true;
        case 9: pp->setQ3(string2long(value)); return true;
        case 10: pp->setQ4(string2long(value)); return true;
        case 11: pp->setQ5(string2long(value)); return true;
        case 12: pp->setLastTS(string2double(value)); return true;
        case 13: pp->setT2(string2double(value)); return true;
        case 14: pp->setT3(string2double(value)); return true;
        case 15: pp->setT4(string2double(value)); return true;
        case 16: pp->setT5(string2double(value)); return true;
        case 17: pp->setRouting(string2long(value)); return true;
        default: return false;
    }
}

const char *DataPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *DataPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DataPacket *pp = (DataPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


