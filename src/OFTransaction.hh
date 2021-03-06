/*
 * Copyright 2015 Applied Research Center for Computer Networks
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Common.hh"
#include "OFMsgUnion.hh"

/**
* Used to serve response from the switch.
*/
class OFTransaction : public QObject {
    Q_OBJECT
public:
    explicit OFTransaction(uint32_t xid, QObject *parent = 0);

    /**
    * Sends an OpenFlow message.
    * @param ofconn Connection to use.
    * @param msg OpenFlow Message (xid will be overwritten).
    */
    void request(OFConnection* ofconn, OFMsg* msg);

signals:
    /**
    * New response message received on this transaction.
    *
    * @param ofconn     OpenFlow Connection.
    * @param reply        Unpacked OpenFlow message.
    */
    void response(OFConnection* ofconn, std::shared_ptr<OFMsgUnion> reply);

    /**
    * Indicates about error on the switch.
    *
    * @param ofconn     OpenFlow Connection.
    * @param error      Information about error.
    */
    void error(OFConnection* ofconn, std::shared_ptr<OFMsgUnion> error);

private:
    uint32_t m_xid;
};

