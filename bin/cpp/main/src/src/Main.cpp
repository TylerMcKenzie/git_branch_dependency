// Generated by Haxe 3.4.7
#include <hxcpp.h>

#ifndef INCLUDED_app_App
#include <app/App.h>
#endif
#ifndef INCLUDED_src_Main
#include <src/Main.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_3cb1ff7e3af8b400_7_main,"src.Main","main",0xed2a5664,"src.Main.main","Main.hx",7,0x087e5c05)
namespace src{

void Main_obj::__construct() { }

Dynamic Main_obj::__CreateEmpty() { return new Main_obj; }

void *Main_obj::_hx_vtable = 0;

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< Main_obj > _hx_result = new Main_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Main_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x18d5e0fd;
}

void Main_obj::main(){
            	HX_GC_STACKFRAME(&_hx_pos_3cb1ff7e3af8b400_7_main)
HXLINE(   8)		 ::app::App app1 =  ::app::App_obj::__alloc( HX_CTX );
HXLINE(   9)		app1->run();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

bool Main_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { outValue = main_dyn(); return true; }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *Main_obj_sMemberStorageInfo = 0;
static hx::StaticInfo *Main_obj_sStaticStorageInfo = 0;
#endif

static void Main_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Main_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

hx::Class Main_obj::__mClass;

static ::String Main_obj_sStaticFields[] = {
	HX_HCSTRING("main","\x39","\x38","\x56","\x48"),
	::String(null())
};

void Main_obj::__register()
{
	hx::Object *dummy = new Main_obj;
	Main_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("src.Main","\x23","\xf2","\x2a","\x7b");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Main_obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = Main_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(Main_obj_sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Main_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Main_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Main_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Main_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace src
