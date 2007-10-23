/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <activemq/connector/openwire/marshal/v2/RemoveSubscriptionInfoMarshallerTest.h>

#include <activemq/connector/openwire/marshal/v2/RemoveSubscriptionInfoMarshaller.h>
#include <activemq/connector/openwire/commands/RemoveSubscriptionInfo.h>

CPPUNIT_TEST_SUITE_REGISTRATION( activemq::connector::openwire::marshal::v2::RemoveSubscriptionInfoMarshallerTest );

#include <activemq/io/DataInputStream.h>
#include <activemq/io/DataOutputStream.h>
#include <activemq/io/IOException.h>
#include <activemq/connector/openwire/OpenWireFormat.h>
#include <activemq/connector/openwire/commands/DataStructure.h>
#include <activemq/connector/openwire/utils/BooleanStream.h>
#include <activemq/io/ByteArrayOutputStream.h>
#include <activemq/io/ByteArrayInputStream.h>
#include <activemq/util/Properties.h>
//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::util;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::utils;
using namespace activemq::connector::openwire::marshal::v2;

///////////////////////////////////////////////////////////////////////////////
void RemoveSubscriptionInfoMarshallerTest::test() {

    RemoveSubscriptionInfoMarshaller myMarshaller;
    RemoveSubscriptionInfo myCommand;
    RemoveSubscriptionInfo* myCommand2;

    CPPUNIT_ASSERT( myMarshaller.getDataStructureType() == myCommand.getDataStructureType() );
    myCommand2 = dynamic_cast<RemoveSubscriptionInfo*>( myMarshaller.createObject() );
    CPPUNIT_ASSERT( myCommand2 != NULL );
    delete myCommand2;
}

///////////////////////////////////////////////////////////////////////////////
void RemoveSubscriptionInfoMarshallerTest::testLooseMarshal() {

    RemoveSubscriptionInfoMarshaller marshaller;
    Properties props;
    OpenWireFormat openWireFormat( props );

    // Configure for this test.
    openWireFormat.setVersion( 2 );
    openWireFormat.setTightEncodingEnabled( false );

    RemoveSubscriptionInfo outCommand;
    RemoveSubscriptionInfo inCommand;

    try {

        // Marshal the dataStructure to a byte array.
        ByteArrayOutputStream baos;
        DataOutputStream dataOut( &baos );
        dataOut.writeByte( outCommand.getDataStructureType() );
        marshaller.looseMarshal( &openWireFormat, &outCommand, &dataOut );

        // Now read it back in and make sure it's all right.
        ByteArrayInputStream bais( baos.getByteArray(), baos.getByteArraySize() );
        DataInputStream dataIn( &bais );
        unsigned char dataType = dataIn.readByte();
        CPPUNIT_ASSERT( dataType == outCommand.getDataStructureType() );
        marshaller.looseUnmarshal( &openWireFormat, &inCommand, &dataIn );

        CPPUNIT_ASSERT( inCommand.equals( &outCommand ) == true );

    } catch( ActiveMQException& e ) {
        e.printStackTrace();
        CPPUNIT_ASSERT( false );
    } catch( ... ) {
        CPPUNIT_ASSERT( false );
    }
}

///////////////////////////////////////////////////////////////////////////////
void RemoveSubscriptionInfoMarshallerTest::testTightMarshal() {

    RemoveSubscriptionInfoMarshaller marshaller;
    Properties props;
    OpenWireFormat openWireFormat( props );

    // Configure for this test.
    openWireFormat.setVersion( 2 );
    openWireFormat.setTightEncodingEnabled( true );

    RemoveSubscriptionInfo outCommand;
    RemoveSubscriptionInfo inCommand;

    try {

        // Marshal the dataStructure to a byte array.
        ByteArrayOutputStream baos;
        DataOutputStream dataOut( &baos );
        // Phase 1 - count the size
        int size = 1;
        BooleanStream bs;
        size += marshaller.tightMarshal1( &openWireFormat, &outCommand, &bs );
        size += bs.marshalledSize();
        // Phase 2 - marshal
        dataOut.writeByte( outCommand.getDataStructureType() );
        bs.marshal( &dataOut );
        marshaller.tightMarshal2( &openWireFormat, &outCommand, &dataOut, &bs );

        // Now read it back in and make sure it's all right.
        ByteArrayInputStream bais( baos.getByteArray(), baos.getByteArraySize() );
        DataInputStream dataIn( &bais );

        unsigned char dataType = dataIn.readByte();
        CPPUNIT_ASSERT( dataType == outCommand.getDataStructureType() );
        bs.clear();
        bs.unmarshal( &dataIn );
        marshaller.tightUnmarshal( &openWireFormat, &inCommand, &dataIn, &bs );

        CPPUNIT_ASSERT( inCommand.equals( &outCommand ) == true );

    } catch( ActiveMQException& e ) {
        e.printStackTrace();
        CPPUNIT_ASSERT( false );
    } catch( ... ) {
        CPPUNIT_ASSERT( false );
    }
}

