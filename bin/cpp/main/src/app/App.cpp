// Generated by Haxe 3.4.7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_app_App
#include <app/App.h>
#endif
#ifndef INCLUDED_app_model_DependencyModel
#include <app/model/DependencyModel.h>
#endif
#ifndef INCLUDED_app_util_Formatter
#include <app/util/Formatter.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_sys_io_Process
#include <sys/io/Process.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_13_new,"app.App","new",0x7811b126,"app.App.new","app/App.hx",13,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_20_run,"app.App","run",0x7814c811,"app.App.run","app/App.hx",20,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_52_addDependency,"app.App","addDependency",0xb0ef3492,"app.App.addDependency","app/App.hx",52,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_58_removeDependency,"app.App","removeDependency",0x4196cfa9,"app.App.removeDependency","app/App.hx",58,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_64_updateDependencyRemotes,"app.App","updateDependencyRemotes",0x1761f31f,"app.App.updateDependencyRemotes","app/App.hx",64,0x9296abcb)
static const ::String _hx_array_data_2514e634_11[] = {
	HX_("pull",c5,0b,61,4a),HX_("origin",e6,19,01,4b),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_124_updateBranch,"app.App","updateBranch",0x1dfb7c05,"app.App.updateBranch","app/App.hx",124,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_128_checkDependencyRemoteStatus,"app.App","checkDependencyRemoteStatus",0x9ece2b71,"app.App.checkDependencyRemoteStatus","app/App.hx",128,0x9296abcb)
static const ::String _hx_array_data_2514e634_15[] = {
	HX_("branch",a2,fe,18,13),HX_("ahead",01,6e,e9,1e),HX_("behind",ba,30,80,9b),HX_("status",32,e7,fb,05),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_149_getBranchRemoteStatus,"app.App","getBranchRemoteStatus",0x26326096,"app.App.getBranchRemoteStatus","app/App.hx",149,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_162_getBranchMergeStatus,"app.App","getBranchMergeStatus",0xa8d1a78c,"app.App.getBranchMergeStatus","app/App.hx",162,0x9296abcb)
static const ::String _hx_array_data_2514e634_19[] = {
	HX_("branch",a2,fe,18,13),HX_("--merged",0c,ae,2b,65),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_174_getCurrentBranch,"app.App","getCurrentBranch",0x51bac4bf,"app.App.getCurrentBranch","app/App.hx",174,0x9296abcb)
static const ::String _hx_array_data_2514e634_21[] = {
	HX_("rev-parse",89,52,b1,66),HX_("--abbrev-ref",48,a7,a8,ad),HX_("HEAD",20,f1,cb,2f),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_187_updateRemotes,"app.App","updateRemotes",0x6e49d46a,"app.App.updateRemotes","app/App.hx",187,0x9296abcb)
static const ::String _hx_array_data_2514e634_23[] = {
	HX_("remote",86,9a,88,04),HX_("update",09,86,05,87),
};
namespace app{

void App_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_13_new)
HXLINE(  14)		this->formatter =  ::app::util::Formatter_obj::__alloc( HX_CTX ,null());
HXLINE(  15)		this->dependencyModel =  ::app::model::DependencyModel_obj::__alloc( HX_CTX );
HXLINE(  16)		 ::app::model::DependencyModel _hx_tmp = this->dependencyModel;
HXDLIN(  16)		_hx_tmp->loadDependencies(this->getCurrentBranch());
            	}

Dynamic App_obj::__CreateEmpty() { return new App_obj; }

void *App_obj::_hx_vtable = 0;

Dynamic App_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< App_obj > _hx_result = new App_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool App_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x313f5580;
}

void App_obj::run(){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_20_run)
HXLINE(  21)		::Array< ::String > args = ::Sys_obj::args();
HXLINE(  23)		{
HXLINE(  23)			int _g1 = (int)0;
HXDLIN(  23)			int _g = args->length;
HXDLIN(  23)			while((_g1 < _g)){
HXLINE(  23)				_g1 = (_g1 + (int)1);
HXDLIN(  23)				int i = (_g1 - (int)1);
HXLINE(  24)				{
HXLINE(  24)					::String _g2 = args->__get(i);
HXDLIN(  24)					::String _hx_switch_0 = _g2;
            					if (  (_hx_switch_0==HX_("-a",94,27,00,00)) ){
HXLINE(  42)						::String dep = args->__get((i + (int)1));
HXLINE(  43)						this->addDependency(dep);
HXLINE(  41)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("-d",97,27,00,00)) ){
HXLINE(  45)						::String dep1 = args->__get((i + (int)1));
HXLINE(  46)						this->removeDependency(dep1);
HXLINE(  44)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("list",5e,1c,b3,47)) ){
HXLINE(  26)						::String currBranch = this->getCurrentBranch();
HXLINE(  27)						::Sys_obj::println(((HX_("Showing dependencies for [",68,fb,ca,cc) + currBranch) + HX_("]:",3d,51,00,00)));
HXLINE(  28)						{
HXLINE(  28)							int _g21 = (int)0;
HXDLIN(  28)							::Array< ::String > _g3 = this->dependencyModel->getDependencies();
HXDLIN(  28)							while((_g21 < _g3->length)){
HXLINE(  28)								::String dependency = _g3->__get(_g21);
HXDLIN(  28)								_g21 = (_g21 + (int)1);
HXLINE(  29)								::Sys_obj::println(dependency);
            							}
            						}
HXLINE(  25)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("status",32,e7,fb,05)) ){
HXLINE(  32)						::Sys_obj::println(HX_("Checking for remote updates...",01,45,f1,90));
HXLINE(  33)						this->updateRemotes();
HXLINE(  35)						this->checkDependencyRemoteStatus();
HXLINE(  31)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("update",09,86,05,87)) ){
HXLINE(  37)						::Sys_obj::println(HX_("Updating remotes...",1b,cd,e7,4e));
HXLINE(  38)						this->updateRemotes();
HXLINE(  40)						this->updateDependencyRemotes();
HXLINE(  36)						goto _hx_goto_2;
            					}
            					_hx_goto_2:;
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,run,(void))

void App_obj::addDependency(::String dependency){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_52_addDependency)
HXLINE(  53)		this->dependencyModel->addDependency(dependency);
HXLINE(  54)		this->dependencyModel->save();
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,addDependency,(void))

void App_obj::removeDependency(::String dependency){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_58_removeDependency)
HXLINE(  59)		this->dependencyModel->removeDependency(dependency);
HXLINE(  60)		this->dependencyModel->save();
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,removeDependency,(void))

void App_obj::updateDependencyRemotes(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_64_updateDependencyRemotes)
HXLINE(  65)		::Array< ::String > deps = this->dependencyModel->getDependencies();
HXLINE(  66)		bool updated = false;
HXLINE(  68)		::Array< ::String > preparedBranches = ::Array_obj< ::String >::__new(0);
HXLINE(  70)		{
HXLINE(  70)			int _g = (int)0;
HXDLIN(  70)			while((_g < deps->length)){
HXLINE(  70)				::String dep = deps->__get(_g);
HXDLIN(  70)				_g = (_g + (int)1);
HXLINE(  71)				 ::Dynamic dependencyStatus = this->getBranchRemoteStatus(dep);
HXLINE(  73)				if (hx::IsGreater( ::Std_obj::parseInt(( (::String)(dependencyStatus->__Field(HX_("behind",ba,30,80,9b),hx::paccDynamic)) )),(int)0 )) {
HXLINE(  74)					this->updateBranch(dep);
            				}
HXLINE(  77)				if ((this->getBranchMergeStatus(dep) == HX_("unmerged",c5,ed,4e,0a))) {
HXLINE(  78)					preparedBranches->push(dep);
            				}
            			}
            		}
HXLINE(  82)		if ((preparedBranches->length > (int)0)) {
HXLINE(  83)			::Array< ::String > gitPullArgs = ::Array_obj< ::String >::fromData( _hx_array_data_2514e634_11,2)->concat(preparedBranches);
HXLINE(  84)			gitPullArgs->push(HX_("--no-ff",ac,19,ea,ec));
HXLINE(  87)			if ((::Sys_obj::command(HX_("git",12,84,4e,00),gitPullArgs) != (int)0)) {
HXLINE(  88)				::Sys_obj::println(HX_("Falling back to indiviually merging dependencies.",c5,6a,06,14));
HXLINE(  90)				 ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git reset --hard",4a,05,8a,31),null())->exitCode(null());
HXLINE(  92)				{
HXLINE(  92)					int _g1 = (int)0;
HXDLIN(  92)					while((_g1 < preparedBranches->length)){
HXLINE(  92)						::String branch = preparedBranches->__get(_g1);
HXDLIN(  92)						_g1 = (_g1 + (int)1);
HXLINE(  93)						if ((::Sys_obj::command(HX_("git",12,84,4e,00),::Array_obj< ::String >::__new(4)->init(0,HX_("pull",c5,0b,61,4a))->init(1,HX_("origin",e6,19,01,4b))->init(2,branch)->init(3,HX_("--no-ff",ac,19,ea,ec))) != (int)0)) {
HXLINE(  94)							::String diffFiles =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git diff --diff-filter=U --name-only",f9,83,2d,eb),null())->_hx_stdout->readAll(null())->toString();
HXLINE(  96)							::Array< ::String > unmergedFiles = ::Array_obj< ::String >::__new(0);
HXLINE(  97)							{
HXLINE(  97)								int _g11 = (int)0;
HXDLIN(  97)								::Array< ::String > _g2 = diffFiles.split(HX_("\n",0a,00,00,00));
HXDLIN(  97)								while((_g11 < _g2->length)){
HXLINE(  97)									::String file = _g2->__get(_g11);
HXDLIN(  97)									_g11 = (_g11 + (int)1);
HXLINE(  98)									if ((file.length > (int)0)) {
HXLINE(  99)										unmergedFiles->push(::StringTools_obj::trim(file));
            									}
            								}
            							}
HXLINE( 104)							::String editor = ::StringTools_obj::trim( ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git config --global core.editor",0f,e7,57,b7),null())->_hx_stdout->readAll(null())->toString());
HXLINE( 106)							if ((editor.length > (int)0)) {
HXLINE( 107)								if ((unmergedFiles->length > (int)0)) {
HXLINE( 108)									if ((::Sys_obj::command(editor,unmergedFiles) != (int)0)) {
HXLINE( 109)										::Sys_obj::println(((HX_("An error occurred when opening '",a9,fd,66,4c) + editor) + HX_("'",27,00,00,00)));
HXLINE( 110)										return;
            									}
            								}
            							}
            						}
            					}
            				}
            			}
            		}
            		else {
HXLINE( 118)			::Sys_obj::println(HX_("Nothing updated.",26,28,b7,61));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,updateDependencyRemotes,(void))

void App_obj::updateBranch(::String branch){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_124_updateBranch)
HXDLIN( 124)		 ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::__new(3)->init(0,HX_("fetch",3a,14,fa,fd))->init(1,HX_("origin",e6,19,01,4b))->init(2,(((HX_("",00,00,00,00) + branch) + HX_(":",3a,00,00,00)) + branch)))->exitCode(null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,updateBranch,(void))

void App_obj::checkDependencyRemoteStatus(){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_128_checkDependencyRemoteStatus)
HXLINE( 129)		::Array< ::String > deps = this->dependencyModel->getDependencies();
HXLINE( 131)		::Array< ::Dynamic> branchRows = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 132)		{
HXLINE( 132)			int _g = (int)0;
HXDLIN( 132)			while((_g < deps->length)){
HXLINE( 132)				::String dep = deps->__get(_g);
HXDLIN( 132)				_g = (_g + (int)1);
HXLINE( 133)				 ::Dynamic status = this->getBranchRemoteStatus(dep);
HXLINE( 135)				::String mergedStatus = this->getBranchMergeStatus(dep);
HXLINE( 142)				branchRows->push(::Array_obj< ::String >::__new(4)->init(0,dep)->init(1, ::Dynamic(status->__Field(HX_("ahead",01,6e,e9,1e),hx::paccDynamic)))->init(2, ::Dynamic(status->__Field(HX_("behind",ba,30,80,9b),hx::paccDynamic)))->init(3,mergedStatus));
            			}
            		}
HXLINE( 145)		this->formatter->printTable(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_15,4),branchRows);
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,checkDependencyRemoteStatus,(void))

 ::Dynamic App_obj::getBranchRemoteStatus(::String branch){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_149_getBranchRemoteStatus)
HXLINE( 150)		::String branchToOrigin = (((HX_("",00,00,00,00) + branch) + HX_("...origin/",5b,79,c8,11)) + branch);
HXLINE( 152)		::String ahead = ::StringTools_obj::trim( ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::__new(4)->init(0,HX_("rev-list",c8,76,46,3f))->init(1,HX_("--left-only",52,0b,9d,28))->init(2,HX_("--count",6f,61,b8,97))->init(3,branchToOrigin))->_hx_stdout->readAll(null())->toString());
HXLINE( 153)		::String behind = ::StringTools_obj::trim( ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::__new(4)->init(0,HX_("rev-list",c8,76,46,3f))->init(1,HX_("--right-only",1d,36,11,d8))->init(2,HX_("--count",6f,61,b8,97))->init(3,branchToOrigin))->_hx_stdout->readAll(null())->toString());
HXLINE( 155)		return  ::Dynamic(hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("behind",ba,30,80,9b),behind)
            			->setFixed(1,HX_("ahead",01,6e,e9,1e),ahead));
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,getBranchRemoteStatus,return )

::String App_obj::getBranchMergeStatus(::String branch){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_162_getBranchMergeStatus)
HXLINE( 163)		::Array< ::String > dirtyMergedBranches =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_19,2))->_hx_stdout->readAll(null())->toString().split(HX_("\n",0a,00,00,00));
HXLINE( 164)		::Array< ::String > _g = ::Array_obj< ::String >::__new(0);
HXDLIN( 164)		{
HXLINE( 164)			int _g1 = (int)0;
HXDLIN( 164)			while((_g1 < dirtyMergedBranches->length)){
HXLINE( 164)				::String dB = dirtyMergedBranches->__get(_g1);
HXDLIN( 164)				_g1 = (_g1 + (int)1);
HXDLIN( 164)				_g->push(::StringTools_obj::trim(dB));
            			}
            		}
HXDLIN( 164)		::Array< ::String > cleanMergedBranches = _g;
HXLINE( 166)		if ((cleanMergedBranches->indexOf(branch,null()) == (int)-1)) {
HXLINE( 167)			return HX_("unmerged",c5,ed,4e,0a);
            		}
HXLINE( 170)		return HX_("merged",ac,be,07,08);
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,getBranchMergeStatus,return )

::String App_obj::getCurrentBranch(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_174_getCurrentBranch)
HXLINE( 175)		 ::sys::io::Process process =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_21,3));
HXLINE( 177)		process->exitCode(null());
HXLINE( 179)		::String b = ::StringTools_obj::trim(process->_hx_stdout->readAll(null())->toString());
HXLINE( 181)		return b;
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,getCurrentBranch,return )

void App_obj::updateRemotes(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_187_updateRemotes)
HXDLIN( 187)		 ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_23,2))->exitCode(null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,updateRemotes,(void))


hx::ObjectPtr< App_obj > App_obj::__new() {
	hx::ObjectPtr< App_obj > __this = new App_obj();
	__this->__construct();
	return __this;
}

hx::ObjectPtr< App_obj > App_obj::__alloc(hx::Ctx *_hx_ctx) {
	App_obj *__this = (App_obj*)(hx::Ctx::alloc(_hx_ctx, sizeof(App_obj), true, "app.App"));
	*(void **)__this = App_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

App_obj::App_obj()
{
}

void App_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(App);
	HX_MARK_MEMBER_NAME(dependencyModel,"dependencyModel");
	HX_MARK_MEMBER_NAME(formatter,"formatter");
	HX_MARK_END_CLASS();
}

void App_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(dependencyModel,"dependencyModel");
	HX_VISIT_MEMBER_NAME(formatter,"formatter");
}

hx::Val App_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return hx::Val( run_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"formatter") ) { return hx::Val( formatter ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateBranch") ) { return hx::Val( updateBranch_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"addDependency") ) { return hx::Val( addDependency_dyn() ); }
		if (HX_FIELD_EQ(inName,"updateRemotes") ) { return hx::Val( updateRemotes_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"dependencyModel") ) { return hx::Val( dependencyModel ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeDependency") ) { return hx::Val( removeDependency_dyn() ); }
		if (HX_FIELD_EQ(inName,"getCurrentBranch") ) { return hx::Val( getCurrentBranch_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getBranchMergeStatus") ) { return hx::Val( getBranchMergeStatus_dyn() ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getBranchRemoteStatus") ) { return hx::Val( getBranchRemoteStatus_dyn() ); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"updateDependencyRemotes") ) { return hx::Val( updateDependencyRemotes_dyn() ); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"checkDependencyRemoteStatus") ) { return hx::Val( checkDependencyRemoteStatus_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

hx::Val App_obj::__SetField(const ::String &inName,const hx::Val &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"formatter") ) { formatter=inValue.Cast<  ::app::util::Formatter >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"dependencyModel") ) { dependencyModel=inValue.Cast<  ::app::model::DependencyModel >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void App_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("dependencyModel","\xde","\xfc","\x7e","\xd4"));
	outFields->push(HX_HCSTRING("formatter","\x0a","\xeb","\x67","\x19"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo App_obj_sMemberStorageInfo[] = {
	{hx::fsObject /*::app::model::DependencyModel*/ ,(int)offsetof(App_obj,dependencyModel),HX_HCSTRING("dependencyModel","\xde","\xfc","\x7e","\xd4")},
	{hx::fsObject /*::app::util::Formatter*/ ,(int)offsetof(App_obj,formatter),HX_HCSTRING("formatter","\x0a","\xeb","\x67","\x19")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *App_obj_sStaticStorageInfo = 0;
#endif

static ::String App_obj_sMemberFields[] = {
	HX_HCSTRING("dependencyModel","\xde","\xfc","\x7e","\xd4"),
	HX_HCSTRING("formatter","\x0a","\xeb","\x67","\x19"),
	HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),
	HX_HCSTRING("addDependency","\x4c","\x60","\x12","\x01"),
	HX_HCSTRING("removeDependency","\x2f","\x34","\x72","\x50"),
	HX_HCSTRING("updateDependencyRemotes","\x59","\xcb","\xe2","\x0e"),
	HX_HCSTRING("updateBranch","\x8b","\xa5","\xdc","\x12"),
	HX_HCSTRING("checkDependencyRemoteStatus","\xab","\xa8","\xd8","\x48"),
	HX_HCSTRING("getBranchRemoteStatus","\x50","\xd6","\x5e","\xa1"),
	HX_HCSTRING("getBranchMergeStatus","\x12","\xc7","\xe0","\xfa"),
	HX_HCSTRING("getCurrentBranch","\x45","\x29","\x96","\x60"),
	HX_HCSTRING("updateRemotes","\x24","\x00","\x6d","\xbe"),
	::String(null()) };

static void App_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(App_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void App_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(App_obj::__mClass,"__mClass");
};

#endif

hx::Class App_obj::__mClass;

void App_obj::__register()
{
	hx::Object *dummy = new App_obj;
	App_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("app.App","\x34","\xe6","\x14","\x25");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = App_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(App_obj_sMemberFields);
	__mClass->mCanCast = hx::TCanCast< App_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = App_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = App_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = App_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace app
