#set has_constructor = False
#if $current_class.methods.has_key('constructor')
#set has_constructor = True
${current_class.methods.constructor.generate_code($current_class)}
#end if

#set generator = $current_class.generator
#set methods = $current_class.methods_clean()
#set st_methods = $current_class.static_methods_clean()

#if len($current_class.parents) > 0
extern JSObject *js_${current_class.parents[0].class_name}_prototype;
#end if

void js_${current_class.class_name}_finalize(JSFreeOp *fop, JSObject *obj) {
//#ifdef COCOS2D_JAVASCRIPT
	LOGD("js_${current_class.class_name}_finalize\n");
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
//#endif 
}

void js_register_${generator.prefix}_${current_class.class_name}(JSContext *cx, JSObject *global) {
	js_${current_class.class_name}_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_${current_class.class_name}_class->name = "${current_class.target_class_name}";
	js_${current_class.class_name}_class->addProperty = JS_PropertyStub;
	js_${current_class.class_name}_class->delProperty = JS_PropertyStub;
	js_${current_class.class_name}_class->getProperty = JS_PropertyStub;
	js_${current_class.class_name}_class->setProperty = JS_StrictPropertyStub;
	js_${current_class.class_name}_class->enumerate = JS_EnumerateStub;
	js_${current_class.class_name}_class->resolve = JS_ResolveStub;
	js_${current_class.class_name}_class->convert = JS_ConvertStub;
	js_${current_class.class_name}_class->finalize = js_${current_class.class_name}_finalize;
	js_${current_class.class_name}_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	#if len($current_class.fields) > 0
	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};
	#else
	JSPropertySpec *properties = NULL;
	#end if

	#if len(methods) > 0
	static JSFunctionSpec funcs[] = {
		#for m in methods
		#set fn = m['impl']
		JS_FN("${m['name']}", ${fn.signature_name}, ${fn.min_args}, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		#end for
		JS_FS_END
	};
	#else
	JSFunctionSpec *funcs = NULL;
	#end if

	#if len(st_methods) > 0
	static JSFunctionSpec st_funcs[] = {
		#for m in st_methods
		#set fn = m['impl']
		JS_FN("${m['name']}", ${fn.signature_name}, ${fn.min_args}, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		#end for
		JS_FS_END
	};
	#else
	JSFunctionSpec *st_funcs = NULL;
	#end if

	js_${current_class.class_name}_prototype = JS_InitClass(
		cx, global,
#if len($current_class.parents) > 0
		js_${current_class.parents[0].class_name}_prototype,
#else
		NULL, // parent proto
#end if
		js_${current_class.class_name}_class,
#if has_constructor
		js_${current_class.class_name}_constructor, 0, // constructor
#else if $current_class.is_abstract
		empty_constructor, 0,
#else
		dummy_constructor<${current_class.namespaced_class_name}>, 0, // no constructor
#end if
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "${current_class.target_class_name}", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<${current_class.namespaced_class_name}> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_${current_class.class_name}_class;
		p->proto = js_${current_class.class_name}_prototype;
#if len($current_class.parents) > 0
		p->parentProto = js_${current_class.parents[0].class_name}_prototype;
#else
		p->parentProto = NULL;
#end if
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

