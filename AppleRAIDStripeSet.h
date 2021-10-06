/*
 * Copyright (c) 2001-2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 *
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */


#ifndef _APPLERAIDSTRIPESET_H
#define _APPLERAIDSTRIPESET_H

#define kAppleRAIDLevelNameStripe "Stripe"

extern const OSSymbol * gAppleRAIDStripeName;

class AppleRAIDStripeSet : public AppleRAIDSet
{
    OSDeclareDefaultStructors(AppleRAIDStripeSet);
    
 protected:
    virtual bool init();
    virtual void free();

 public:
    static AppleRAIDSet * createRAIDSet(AppleRAIDMember * firstMember);
    virtual bool addSpare(AppleRAIDMember * member);
    virtual bool addMember(AppleRAIDMember * member);
    virtual bool startSet(void);

    virtual AppleRAIDMemoryDescriptor * allocateMemoryDescriptor(AppleRAIDStorageRequest *storageRequest, UInt32 memberIndex);
};



class AppleRAIDStripeMemoryDescriptor : public AppleRAIDMemoryDescriptor
{
    OSDeclareDefaultStructors(AppleRAIDStripeMemoryDescriptor);
    
private:
    UInt32		mdMemberCount;
    UInt32		mdSetBlockSize;
    UInt32		mdSetBlockStart;
    UInt32		mdSetBlockOffset;
    
protected:
    virtual bool initWithStorageRequest(AppleRAIDStorageRequest *storageRequest, UInt32 memberIndex);
    virtual bool configureForMemoryDescriptor(IOMemoryDescriptor *memoryDescriptor, UInt64 byteStart, UInt32 activeIndex);
    
 public:
    static AppleRAIDMemoryDescriptor *withStorageRequest(AppleRAIDStorageRequest *storageRequest, UInt32 memberIndex);
    virtual IOPhysicalAddress getPhysicalSegment(IOByteCount offset, IOByteCount *length);
    virtual addr64_t getPhysicalSegment64(IOByteCount offset, IOByteCount *length);
};

#endif /* ! _APPLERAIDSTRIPESET_H */
