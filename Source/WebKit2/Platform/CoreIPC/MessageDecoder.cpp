/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "MessageDecoder.h"

#include "ArgumentCoders.h"
#include "DataReference.h"
#include <wtf/text/CString.h>

namespace CoreIPC {

PassOwnPtr<MessageDecoder> MessageDecoder::create(const DataReference& buffer)
{
    Deque<Attachment> attachments;
    return adoptPtr(new MessageDecoder(buffer, attachments));
}

PassOwnPtr<MessageDecoder> MessageDecoder::create(const DataReference& buffer, Deque<Attachment>& attachments)
{
    return adoptPtr(new MessageDecoder(buffer, attachments));
}

MessageDecoder::~MessageDecoder()
{
}

MessageDecoder::MessageDecoder(const DataReference& buffer, Deque<Attachment>& attachments)
    : ArgumentDecoder(buffer.data(), buffer.size(), attachments)
{
    CString messageReceiverName;
    if (!decode(messageReceiverName))
        return;

    CString messageName;
    if (!decode(messageName))
        return;

    decodeUInt64(m_destinationID);
}

} // namespace CoreIPC
