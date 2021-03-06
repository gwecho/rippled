//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

// VFALCO NOTE this looks like some facility for giving websocket
//         a way to produce logging output.
//
namespace websocketpp
{
namespace log
{

using namespace ripple;

LogPartition websocketPartition ("WebSocket");

void websocketLog (websocketpp::log::alevel::value v, const std::string& entry)
{
    using namespace ripple;

    if ((v == websocketpp::log::alevel::DEVEL) || (v == websocketpp::log::alevel::DEBUG_CLOSE))
    {
        if (websocketPartition.doLog (lsTRACE))
            Log (lsDEBUG, websocketPartition) << entry;
    }
    else if (websocketPartition.doLog (lsDEBUG))
        Log (lsDEBUG, websocketPartition) << entry;
}

void websocketLog (websocketpp::log::elevel::value v, const std::string& entry)
{
    using namespace ripple;

    LogSeverity s = lsDEBUG;

    if ((v & websocketpp::log::elevel::INFO) != 0)
        s = lsINFO;
    else if ((v & websocketpp::log::elevel::FATAL) != 0)
        s = lsFATAL;
    else if ((v & websocketpp::log::elevel::RERROR) != 0)
        s = lsERROR;
    else if ((v & websocketpp::log::elevel::WARN) != 0)
        s = lsWARNING;

    if (websocketPartition.doLog (s))
        Log (s, websocketPartition) << entry;
}

}
}

// vim:ts=4
