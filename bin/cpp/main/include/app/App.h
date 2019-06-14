// Generated by Haxe 3.4.7
#ifndef INCLUDED_app_App
#define INCLUDED_app_App

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(app,App)
HX_DECLARE_CLASS2(app,model,DependencyModel)
HX_DECLARE_CLASS2(app,util,Formatter)

namespace app{


class HXCPP_CLASS_ATTRIBUTES App_obj : public hx::Object
{
	public:
		typedef hx::Object super;
		typedef App_obj OBJ_;
		App_obj();

	public:
		enum { _hx_ClassId = 0x313f5580 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="app.App")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,true,"app.App"); }
		static hx::ObjectPtr< App_obj > __new();
		static hx::ObjectPtr< App_obj > __alloc(hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~App_obj();

		HX_DO_RTTI_ALL;
		hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		hx::Val __SetField(const ::String &inString,const hx::Val &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_HCSTRING("App","\x81","\xb4","\x31","\x00"); }

		 ::app::model::DependencyModel dependencyModel;
		 ::app::util::Formatter formatter;
		::String currentBranch;
		void run();
		::Dynamic run_dyn();

		void addDependency(::String dependency);
		::Dynamic addDependency_dyn();

		void removeDependency(::String dependency);
		::Dynamic removeDependency_dyn();

		void updateDependencyRemotes();
		::Dynamic updateDependencyRemotes_dyn();

		void updateBranch(::String branch);
		::Dynamic updateBranch_dyn();

		void checkDependencyRemoteStatus();
		::Dynamic checkDependencyRemoteStatus_dyn();

		 ::Dynamic getBranchRemoteStatus(::String branch);
		::Dynamic getBranchRemoteStatus_dyn();

		::String getBranchMergeStatus(::String branch);
		::Dynamic getBranchMergeStatus_dyn();

		::String loadCurrentBranch();
		::Dynamic loadCurrentBranch_dyn();

		void updateRemotes();
		::Dynamic updateRemotes_dyn();

		void outputHelp();
		::Dynamic outputHelp_dyn();

};

} // end namespace app

#endif /* INCLUDED_app_App */ 
