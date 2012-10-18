/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef V8TestActiveDOMObject_h
#define V8TestActiveDOMObject_h

#include "TestActiveDOMObject.h"
#include "V8Binding.h"
#include "V8DOMWrapper.h"
#include "WrapperTypeInfo.h"
#include <v8.h>
#include <wtf/HashMap.h>
#include <wtf/text/StringHash.h>

namespace WebCore {

class V8TestActiveDOMObject {
public:
    static const bool hasDependentLifetime = false;
    static bool HasInstance(v8::Handle<v8::Value>);
    static v8::Persistent<v8::FunctionTemplate> GetRawTemplate();
    static v8::Persistent<v8::FunctionTemplate> GetTemplate();
    static TestActiveDOMObject* toNative(v8::Handle<v8::Object> object)
    {
        return reinterpret_cast<TestActiveDOMObject*>(object->GetPointerFromInternalField(v8DOMWrapperObjectIndex));
    }
    inline static v8::Handle<v8::Object> wrap(TestActiveDOMObject*, v8::Handle<v8::Object> creationContext = v8::Handle<v8::Object>(), v8::Isolate* = 0);
    static void derefObject(void*);
    static WrapperTypeInfo info;
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
    static bool namedSecurityCheck(v8::Local<v8::Object> host, v8::Local<v8::Value> key, v8::AccessType, v8::Local<v8::Value> data);
    static bool indexedSecurityCheck(v8::Local<v8::Object> host, uint32_t index, v8::AccessType, v8::Local<v8::Value> data);
    static void installPerContextProperties(v8::Handle<v8::Object>, TestActiveDOMObject*) { }
    static void installPerContextPrototypeProperties(v8::Handle<v8::Object>, ScriptExecutionContext*) { }
private:
    static v8::Handle<v8::Object> wrapSlow(PassRefPtr<TestActiveDOMObject>, v8::Handle<v8::Object> creationContext, v8::Isolate*);
};

v8::Handle<v8::Object> V8TestActiveDOMObject::wrap(TestActiveDOMObject* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
        v8::Handle<v8::Object> wrapper = getDOMObjectMap(isolate).get(impl);
        if (!wrapper.IsEmpty())
            return wrapper;
    return V8TestActiveDOMObject::wrapSlow(impl, creationContext, isolate);
}

inline v8::Handle<v8::Value> toV8(TestActiveDOMObject* impl, v8::Handle<v8::Object> creationContext = v8::Handle<v8::Object>(), v8::Isolate* isolate = 0)
{
    if (!impl)
        return v8NullWithCheck(isolate);
    return V8TestActiveDOMObject::wrap(impl, creationContext, isolate);
}
inline v8::Handle<v8::Value> toV8(PassRefPtr< TestActiveDOMObject > impl, v8::Handle<v8::Object> creationContext = v8::Handle<v8::Object>(), v8::Isolate* isolate = 0)
{
    return toV8(impl.get(), creationContext, isolate);
}

}

#endif // V8TestActiveDOMObject_h
