//
// Generated file, do not edit! Created by nedtool 5.3 from messages/TimerNextPacket.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __TIMERNEXTPACKET_M_H
#define __TIMERNEXTPACKET_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0503
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>messages/TimerNextPacket.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * message TimerNextPacket
 * {
 *     int target;
 *     double lambda;
 * }
 * </pre>
 */
class TimerNextPacket : public ::omnetpp::cMessage
{
  protected:
    int target;
    double lambda;

  private:
    void copy(const TimerNextPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TimerNextPacket&);

  public:
    TimerNextPacket(const char *name=nullptr, short kind=0);
    TimerNextPacket(const TimerNextPacket& other);
    virtual ~TimerNextPacket();
    TimerNextPacket& operator=(const TimerNextPacket& other);
    virtual TimerNextPacket *dup() const override {return new TimerNextPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getTarget() const;
    virtual void setTarget(int target);
    virtual double getLambda() const;
    virtual void setLambda(double lambda);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TimerNextPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TimerNextPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef __TIMERNEXTPACKET_M_H
