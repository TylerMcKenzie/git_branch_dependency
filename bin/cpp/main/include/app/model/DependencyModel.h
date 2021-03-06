// Generated by Haxe 4.0.0+ef18b627e
#ifndef INCLUDED_app_model_DependencyModel
#define INCLUDED_app_model_DependencyModel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(app,model,DependencyModel)

namespace app{
namespace model{


class HXCPP_CLASS_ATTRIBUTES DependencyModel_obj : public hx::Object
{
	public:
		typedef hx::Object super;
		typedef DependencyModel_obj OBJ_;
		DependencyModel_obj();

	public:
		enum { _hx_ClassId = 0x0fb17296 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="app.model.DependencyModel")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,true,"app.model.DependencyModel"); }
		static hx::ObjectPtr< DependencyModel_obj > __new();
		static hx::ObjectPtr< DependencyModel_obj > __alloc(hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DependencyModel_obj();

		HX_DO_RTTI_ALL;
		hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		hx::Val __SetField(const ::String &inString,const hx::Val &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("DependencyModel",be,04,0b,35); }

		::String JSON_FILE;
		::String currentBranch;
		::Array< ::String > dependencies;
		 ::Dynamic dependencyGraph;
		void save();
		::Dynamic save_dyn();

		::Array< ::String > getDependencies();
		::Dynamic getDependencies_dyn();

		bool addDependency(::String dependency);
		::Dynamic addDependency_dyn();

		bool removeDependency(::String dependency);
		::Dynamic removeDependency_dyn();

		void loadDependencies(::String branch);
		::Dynamic loadDependencies_dyn();

		void loadDependencyGraph();
		::Dynamic loadDependencyGraph_dyn();

		::String getRootDirectory();
		::Dynamic getRootDirectory_dyn();

};

} // end namespace app
} // end namespace model

#endif /* INCLUDED_app_model_DependencyModel */ 
