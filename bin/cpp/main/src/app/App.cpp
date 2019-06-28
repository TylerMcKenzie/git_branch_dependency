// Generated by Haxe 3.4.7
#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
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

HX_DEFINE_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_36_new,"app.App","new",0x7811b126,"app.App.new","app/App.hx",36,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_51_run,"app.App","run",0x7814c811,"app.App.run","app/App.hx",51,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_126_addDependency,"app.App","addDependency",0xb0ef3492,"app.App.addDependency","app/App.hx",126,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_132_removeDependency,"app.App","removeDependency",0x4196cfa9,"app.App.removeDependency","app/App.hx",132,0x9296abcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_138_updateDependencyRemotes,"app.App","updateDependencyRemotes",0x1761f31f,"app.App.updateDependencyRemotes","app/App.hx",138,0x9296abcb)
static const ::String _hx_array_data_2514e634_11[] = {
	HX_("origin",e6,19,01,4b),
};
static const ::String _hx_array_data_2514e634_12[] = {
	HX_("pull",c5,0b,61,4a),
};
static const ::String _hx_array_data_2514e634_13[] = {
	HX_("reset",cf,49,c8,e6),
};
static const ::String _hx_array_data_2514e634_14[] = {
	HX_("--hard",4b,86,1f,2c),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_177_updateDependencyBranch,"app.App","updateDependencyBranch",0x16b46af0,"app.App.updateDependencyBranch","app/App.hx",177,0x9296abcb)
static const ::String _hx_array_data_2514e634_17[] = {
	HX_("pull",c5,0b,61,4a),
};
static const ::String _hx_array_data_2514e634_18[] = {
	HX_("diff",05,5c,69,42),
};
static const ::String _hx_array_data_2514e634_19[] = {
	HX_("--diff-filter=UU",fd,ec,ab,14),HX_("--name-only",8e,ea,71,0d),
};
static const ::String _hx_array_data_2514e634_20[] = {
	HX_("config",c2,56,d2,c7),
};
static const ::String _hx_array_data_2514e634_21[] = {
	HX_("--global",c3,20,d6,04),HX_("core.editor",dc,d4,6d,6b),
};
static const ::String _hx_array_data_2514e634_22[] = {
	HX_("commit",f7,6f,2e,c7),
};
static const ::String _hx_array_data_2514e634_23[] = {
	HX_("-am",59,7a,22,00),HX_("'Updated merge conflicts'",5a,bc,2c,5b),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_217_updateBranch,"app.App","updateBranch",0x1dfb7c05,"app.App.updateBranch","app/App.hx",217,0x9296abcb)
static const ::String _hx_array_data_2514e634_25[] = {
	HX_("fetch",3a,14,fa,fd),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_221_checkDependencyRemoteStatus,"app.App","checkDependencyRemoteStatus",0x9ece2b71,"app.App.checkDependencyRemoteStatus","app/App.hx",221,0x9296abcb)
static const ::String _hx_array_data_2514e634_28[] = {
	HX_("branch",a2,fe,18,13),HX_("ahead",01,6e,e9,1e),HX_("behind",ba,30,80,9b),HX_("status",32,e7,fb,05),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_237_getBranchRemoteStatus,"app.App","getBranchRemoteStatus",0x26326096,"app.App.getBranchRemoteStatus","app/App.hx",237,0x9296abcb)
static const ::String _hx_array_data_2514e634_30[] = {
	HX_("rev-list",c8,76,46,3f),
};
static const ::String _hx_array_data_2514e634_31[] = {
	HX_("rev-list",c8,76,46,3f),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_250_getBranchMergeStatus,"app.App","getBranchMergeStatus",0xa8d1a78c,"app.App.getBranchMergeStatus","app/App.hx",250,0x9296abcb)
static const ::String _hx_array_data_2514e634_34[] = {
	HX_("branch",a2,fe,18,13),
};
static const ::String _hx_array_data_2514e634_35[] = {
	HX_("--merged",0c,ae,2b,65),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_262_loadCurrentBranch,"app.App","loadCurrentBranch",0x6913c4fb,"app.App.loadCurrentBranch","app/App.hx",262,0x9296abcb)
static const ::String _hx_array_data_2514e634_37[] = {
	HX_("rev-parse",89,52,b1,66),
};
static const ::String _hx_array_data_2514e634_38[] = {
	HX_("--abbrev-ref",48,a7,a8,ad),HX_("HEAD",20,f1,cb,2f),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_275_updateRemotes,"app.App","updateRemotes",0x6e49d46a,"app.App.updateRemotes","app/App.hx",275,0x9296abcb)
static const ::String _hx_array_data_2514e634_40[] = {
	HX_("remote",86,9a,88,04),
};
static const ::String _hx_array_data_2514e634_41[] = {
	HX_("update",09,86,05,87),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_279_pruneDependencies,"app.App","pruneDependencies",0xc3c81979,"app.App.pruneDependencies","app/App.hx",279,0x9296abcb)
static const ::String _hx_array_data_2514e634_45[] = {
	HX_("branch",a2,fe,18,13),
};
static const ::String _hx_array_data_2514e634_46[] = {
	HX_("--merged",0c,ae,2b,65),HX_("master",a2,80,20,bb),
};
HX_LOCAL_STACK_FRAME(_hx_pos_0f0f8a6702f060a3_292_outputHelp,"app.App","outputHelp",0xb1c1e65c,"app.App.outputHelp","app/App.hx",292,0x9296abcb)
namespace app{

void App_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_36_new)
HXLINE(  40)		this->input = ::Sys_obj::_hx_stdin();
HXLINE(  44)		this->currentBranch = this->loadCurrentBranch();
HXLINE(  45)		this->formatter =  ::app::util::Formatter_obj::__alloc( HX_CTX ,null());
HXLINE(  46)		this->dependencyModel =  ::app::model::DependencyModel_obj::__alloc( HX_CTX );
HXLINE(  47)		this->dependencyModel->loadDependencies(this->currentBranch);
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
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_51_run)
HXLINE(  52)		::Array< ::String > args = ::Sys_obj::args();
HXLINE(  54)		{
HXLINE(  54)			int _g1 = (int)0;
HXDLIN(  54)			int _g = args->length;
HXDLIN(  54)			while((_g1 < _g)){
HXLINE(  54)				_g1 = (_g1 + (int)1);
HXDLIN(  54)				int i = (_g1 - (int)1);
HXLINE(  55)				{
HXLINE(  55)					::String _g2 = args->__get(i);
HXDLIN(  55)					::String _hx_switch_0 = _g2;
            					if (  (_hx_switch_0==HX_("-a",94,27,00,00)) ||  (_hx_switch_0==HX_("add",21,f2,49,00)) ){
HXLINE( 108)						::String dep = args->__get((i + (int)1));
HXLINE( 109)						this->addDependency(dep);
HXLINE( 107)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("-h",9b,27,00,00)) ||  (_hx_switch_0==HX_("help",c1,32,0b,45)) ){
HXLINE( 119)						this->outputHelp();
HXLINE( 120)						goto _hx_goto_1;
HXLINE( 118)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("-l",9f,27,00,00)) ||  (_hx_switch_0==HX_("list",5e,1c,b3,47)) ){
HXLINE(  57)						::Sys_obj::println(((HX_("Showing dependencies for [",68,fb,ca,cc) + this->currentBranch) + HX_("]:",3d,51,00,00)));
HXLINE(  58)						{
HXLINE(  58)							int _g21 = (int)0;
HXDLIN(  58)							::Array< ::String > _g3 = this->dependencyModel->getDependencies();
HXDLIN(  58)							while((_g21 < _g3->length)){
HXLINE(  58)								::String dependency = _g3->__get(_g21);
HXDLIN(  58)								_g21 = (_g21 + (int)1);
HXLINE(  59)								::Sys_obj::println(dependency);
            							}
            						}
HXLINE(  61)						goto _hx_goto_1;
HXLINE(  56)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("-p",a3,27,00,00)) ||  (_hx_switch_0==HX_("prune",2a,73,94,c8)) ){
HXLINE( 114)						this->updateRemotes();
HXLINE( 116)						this->pruneDependencies();
HXLINE( 117)						goto _hx_goto_1;
HXLINE( 113)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("-u",a8,27,00,00)) ||  (_hx_switch_0==HX_("update",09,86,05,87)) ){
HXLINE(  69)						::Array< ::String > dependencies = this->dependencyModel->getDependencies();
HXLINE(  70)						::Array< ::String > arg_dependencies = ::Array_obj< ::String >::__new(0);
HXLINE(  71)						int j = (i + (int)1);
HXLINE(  73)						if (hx::IsNotNull( args->__get(j) )) {
HXLINE(  74)							if ((dependencies->indexOf(args->__get(j),null()) > (int)-1)) {
HXLINE(  77)								arg_dependencies->push(args->__get(j));
HXLINE(  79)								bool dependencyFound = true;
HXLINE(  80)								while(dependencyFound){
HXLINE(  81)									j = (j + (int)1);
HXLINE(  84)									bool _hx_tmp;
HXDLIN(  84)									if ((dependencies->indexOf(args->__get(j),null()) > (int)-1)) {
HXLINE(  84)										_hx_tmp = (arg_dependencies->indexOf(args->__get(j),null()) < (int)0);
            									}
            									else {
HXLINE(  84)										_hx_tmp = false;
            									}
HXLINE(  83)									if (_hx_tmp) {
HXLINE(  87)										arg_dependencies->push(args->__get(j));
            									}
            									else {
HXLINE(  89)										dependencyFound = false;
            									}
            								}
            							}
            							else {
HXLINE(  93)								::Sys_obj::println(((HX_("[WARN] Branch: '",3b,f1,e8,f4) + args->__get(j)) + HX_("' not found in dependency list.",b2,19,66,71)));
HXLINE(  94)								goto _hx_goto_1;
            							}
            						}
HXLINE(  98)						if ((arg_dependencies->length > (int)0)) {
HXLINE(  99)							dependencies = arg_dependencies;
            						}
HXLINE( 102)						::Sys_obj::println(HX_("Updating remotes...",1b,cd,e7,4e));
HXLINE( 103)						this->updateRemotes();
HXLINE( 105)						this->updateDependencyRemotes(dependencies);
HXLINE( 106)						goto _hx_goto_1;
HXLINE(  68)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("-d",97,27,00,00)) ||  (_hx_switch_0==HX_("delete",2b,c0,d8,6a)) ){
HXLINE( 111)						::String dep1 = args->__get((i + (int)1));
HXLINE( 112)						this->removeDependency(dep1);
HXLINE( 110)						goto _hx_goto_2;
            					}
            					if (  (_hx_switch_0==HX_("-s",a6,27,00,00)) ||  (_hx_switch_0==HX_("status",32,e7,fb,05)) ){
HXLINE(  63)						::Sys_obj::println(HX_("Checking for remote updates...",01,45,f1,90));
HXLINE(  64)						this->updateRemotes();
HXLINE(  66)						this->checkDependencyRemoteStatus();
HXLINE(  67)						goto _hx_goto_1;
HXLINE(  62)						goto _hx_goto_2;
            					}
            					_hx_goto_2:;
            				}
            			}
            			_hx_goto_1:;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,run,(void))

void App_obj::addDependency(::String dependency){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_126_addDependency)
HXLINE( 127)		this->dependencyModel->addDependency(dependency);
HXLINE( 128)		this->dependencyModel->save();
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,addDependency,(void))

void App_obj::removeDependency(::String dependency){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_132_removeDependency)
HXLINE( 133)		this->dependencyModel->removeDependency(dependency);
HXLINE( 134)		this->dependencyModel->save();
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,removeDependency,(void))

void App_obj::updateDependencyRemotes(::Array< ::String > dependencies){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_138_updateDependencyRemotes)
HXLINE( 139)		bool updated = false;
HXLINE( 141)		::Array< ::String > preparedBranches = ::Array_obj< ::String >::__new(0);
HXLINE( 143)		{
HXLINE( 143)			int _g = (int)0;
HXDLIN( 143)			while((_g < dependencies->length)){
HXLINE( 143)				::String dependency = dependencies->__get(_g);
HXDLIN( 143)				_g = (_g + (int)1);
HXLINE( 144)				 ::Dynamic dependencyStatus = this->getBranchRemoteStatus(dependency);
HXLINE( 146)				if (hx::IsGreater( ::Std_obj::parseInt(( (::String)(dependencyStatus->__Field(HX_("behind",ba,30,80,9b),hx::paccDynamic)) )),(int)0 )) {
HXLINE( 147)					this->updateBranch(dependency);
            				}
HXLINE( 150)				if ((this->getBranchMergeStatus(dependency) == HX_("unmerged",c5,ed,4e,0a))) {
HXLINE( 151)					preparedBranches->push(dependency);
            				}
            			}
            		}
HXLINE( 155)		if ((preparedBranches->length > (int)0)) {
HXLINE( 156)			::Array< ::String > gitPullArgs = ::Array_obj< ::String >::fromData( _hx_array_data_2514e634_11,1)->concat(preparedBranches);
HXLINE( 157)			gitPullArgs->push(HX_("--no-ff",ac,19,ea,ec));
HXLINE( 160)			if ((::Sys_obj::command(HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_12,1)->concat(gitPullArgs)) != (int)0)) {
HXLINE( 161)				::Sys_obj::println(HX_("Falling back to indiviually merging dependencies.",c5,6a,06,14));
HXLINE( 163)				 ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_13,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_14,1)))->exitCode(null());
HXLINE( 165)				{
HXLINE( 165)					int _g1 = (int)0;
HXDLIN( 165)					while((_g1 < preparedBranches->length)){
HXLINE( 165)						::String branch = preparedBranches->__get(_g1);
HXDLIN( 165)						_g1 = (_g1 + (int)1);
HXLINE( 166)						if (!(this->updateDependencyBranch(branch))) {
HXLINE( 167)							HX_STACK_DO_THROW(((HX_("There was an error updating: '",63,04,79,33) + branch) + HX_("'",27,00,00,00)));
            						}
            					}
            				}
            			}
            		}
            		else {
HXLINE( 172)			::Sys_obj::println(HX_("Nothing updated.",26,28,b7,61));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,updateDependencyRemotes,(void))

bool App_obj::updateDependencyBranch(::String branch){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_177_updateDependencyBranch)
HXLINE( 178)		if ((::Sys_obj::command(HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_17,1)->concat(::Array_obj< ::String >::__new(3)->init(0,HX_("origin",e6,19,01,4b))->init(1,branch)->init(2,HX_("--no-ff",ac,19,ea,ec)))) != (int)0)) {
HXLINE( 179)			::String diffFiles =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_18,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_19,2)))->_hx_stdout->readAll(null())->toString();
HXLINE( 181)			::Array< ::String > unmergedFiles = ::Array_obj< ::String >::__new(0);
HXLINE( 182)			{
HXLINE( 182)				int _g = (int)0;
HXDLIN( 182)				::Array< ::String > _g1 = diffFiles.split(HX_("\n",0a,00,00,00));
HXDLIN( 182)				while((_g < _g1->length)){
HXLINE( 182)					::String file = _g1->__get(_g);
HXDLIN( 182)					_g = (_g + (int)1);
HXLINE( 183)					if ((file.length > (int)0)) {
HXLINE( 184)						unmergedFiles->push(::StringTools_obj::trim(file));
            					}
            				}
            			}
HXLINE( 189)			::String editor = ::StringTools_obj::trim( ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_20,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_21,2)))->_hx_stdout->readAll(null())->toString());
HXLINE( 191)			if ((editor.length > (int)0)) {
HXLINE( 192)				if ((unmergedFiles->length > (int)0)) {
HXLINE( 193)					if ((::Sys_obj::command(editor,unmergedFiles) != (int)0)) {
HXLINE( 194)						::Sys_obj::println(((HX_("An error occurred when opening '",a9,fd,66,4c) + editor) + HX_("'",27,00,00,00)));
HXLINE( 195)						return false;
            					}
HXLINE( 198)					::Sys_obj::println(HX_("Commit these changes? [Y/n]: ",08,3e,64,1d));
HXLINE( 200)					::String userInput = this->input->readLine();
HXLINE( 201)					 ::EReg confReg =  ::EReg_obj::__alloc( HX_CTX ,HX_("[Yy]",e2,5c,6a,3c),HX_("",00,00,00,00));
HXLINE( 203)					if (confReg->match(userInput)) {
HXLINE( 204)						 ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_22,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_23,2)))->exitCode(null());
            					}
            				}
            			}
            			else {
HXLINE( 208)				return false;
            			}
            		}
HXLINE( 212)		return true;
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,updateDependencyBranch,return )

void App_obj::updateBranch(::String branch){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_217_updateBranch)
HXDLIN( 217)		 ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_25,1)->concat(::Array_obj< ::String >::__new(2)->init(0,HX_("origin",e6,19,01,4b))->init(1,(((HX_("",00,00,00,00) + branch) + HX_(":",3a,00,00,00)) + branch))))->exitCode(null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,updateBranch,(void))

void App_obj::checkDependencyRemoteStatus(){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_221_checkDependencyRemoteStatus)
HXLINE( 222)		::Array< ::String > deps = this->dependencyModel->getDependencies();
HXLINE( 224)		::Array< ::Dynamic> branchRows = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 225)		{
HXLINE( 225)			int _g = (int)0;
HXDLIN( 225)			while((_g < deps->length)){
HXLINE( 225)				::String dep = deps->__get(_g);
HXDLIN( 225)				_g = (_g + (int)1);
HXLINE( 226)				 ::Dynamic status = this->getBranchRemoteStatus(dep);
HXLINE( 228)				::String mergedStatus = this->getBranchMergeStatus(dep);
HXLINE( 230)				branchRows->push(::Array_obj< ::String >::__new(4)->init(0,dep)->init(1, ::Dynamic(status->__Field(HX_("ahead",01,6e,e9,1e),hx::paccDynamic)))->init(2, ::Dynamic(status->__Field(HX_("behind",ba,30,80,9b),hx::paccDynamic)))->init(3,mergedStatus));
            			}
            		}
HXLINE( 233)		this->formatter->printTable(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_28,4),branchRows);
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,checkDependencyRemoteStatus,(void))

 ::Dynamic App_obj::getBranchRemoteStatus(::String branch){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_237_getBranchRemoteStatus)
HXLINE( 238)		::String branchToOrigin = (((HX_("",00,00,00,00) + branch) + HX_("...origin/",5b,79,c8,11)) + branch);
HXLINE( 240)		::String ahead = ::StringTools_obj::trim( ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_30,1)->concat(::Array_obj< ::String >::__new(3)->init(0,HX_("--left-only",52,0b,9d,28))->init(1,HX_("--count",6f,61,b8,97))->init(2,branchToOrigin)))->_hx_stdout->readAll(null())->toString());
HXLINE( 241)		::String behind = ::StringTools_obj::trim( ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_31,1)->concat(::Array_obj< ::String >::__new(3)->init(0,HX_("--right-only",1d,36,11,d8))->init(1,HX_("--count",6f,61,b8,97))->init(2,branchToOrigin)))->_hx_stdout->readAll(null())->toString());
HXLINE( 243)		return  ::Dynamic(hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("behind",ba,30,80,9b),behind)
            			->setFixed(1,HX_("ahead",01,6e,e9,1e),ahead));
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,getBranchRemoteStatus,return )

::String App_obj::getBranchMergeStatus(::String branch){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_250_getBranchMergeStatus)
HXLINE( 251)		::Array< ::String > dirtyMergedBranches =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_34,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_35,1)))->_hx_stdout->readAll(null())->toString().split(HX_("\n",0a,00,00,00));
HXLINE( 252)		::Array< ::String > _g = ::Array_obj< ::String >::__new(0);
HXDLIN( 252)		{
HXLINE( 252)			int _g1 = (int)0;
HXDLIN( 252)			while((_g1 < dirtyMergedBranches->length)){
HXLINE( 252)				::String dB = dirtyMergedBranches->__get(_g1);
HXDLIN( 252)				_g1 = (_g1 + (int)1);
HXDLIN( 252)				_g->push(::StringTools_obj::trim(dB));
            			}
            		}
HXDLIN( 252)		::Array< ::String > cleanMergedBranches = _g;
HXLINE( 254)		if ((cleanMergedBranches->indexOf(branch,null()) == (int)-1)) {
HXLINE( 255)			return HX_("unmerged",c5,ed,4e,0a);
            		}
HXLINE( 258)		return HX_("merged",ac,be,07,08);
            	}


HX_DEFINE_DYNAMIC_FUNC1(App_obj,getBranchMergeStatus,return )

::String App_obj::loadCurrentBranch(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_262_loadCurrentBranch)
HXLINE( 263)		 ::sys::io::Process process =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_37,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_38,2)));
HXLINE( 265)		process->exitCode(null());
HXLINE( 267)		::String b = ::StringTools_obj::trim(process->_hx_stdout->readAll(null())->toString());
HXLINE( 269)		return b;
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,loadCurrentBranch,return )

void App_obj::updateRemotes(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_275_updateRemotes)
HXDLIN( 275)		 ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_40,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_41,1)))->exitCode(null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,updateRemotes,(void))

void App_obj::pruneDependencies(){
            	HX_GC_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_279_pruneDependencies)
HXLINE( 280)		::Array< ::String > dependencies = this->dependencyModel->getDependencies();
HXLINE( 281)		::Array< ::String > masterMergedBranches =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_2514e634_45,1)->concat(::Array_obj< ::String >::fromData( _hx_array_data_2514e634_46,2)))->_hx_stdout->readAll(null())->toString().split(HX_("\n",0a,00,00,00));
HXLINE( 282)		::Array< ::String > _g = ::Array_obj< ::String >::__new(0);
HXDLIN( 282)		{
HXLINE( 282)			int _g1 = (int)0;
HXDLIN( 282)			while((_g1 < masterMergedBranches->length)){
HXLINE( 282)				::String branch = masterMergedBranches->__get(_g1);
HXDLIN( 282)				_g1 = (_g1 + (int)1);
HXDLIN( 282)				_g->push(::StringTools_obj::trim(branch));
            			}
            		}
HXDLIN( 282)		masterMergedBranches = _g;
HXLINE( 284)		{
HXLINE( 284)			int _g11 = (int)0;
HXDLIN( 284)			while((_g11 < dependencies->length)){
HXLINE( 284)				::String dependency = dependencies->__get(_g11);
HXDLIN( 284)				_g11 = (_g11 + (int)1);
HXLINE( 285)				bool _hx_tmp;
HXDLIN( 285)				if ((masterMergedBranches->indexOf(dependency,null()) > (int)-1)) {
HXLINE( 285)					_hx_tmp = (dependency != HX_("master",a2,80,20,bb));
            				}
            				else {
HXLINE( 285)					_hx_tmp = false;
            				}
HXDLIN( 285)				if (_hx_tmp) {
HXLINE( 286)					this->removeDependency(dependency);
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,pruneDependencies,(void))

void App_obj::outputHelp(){
            	HX_STACKFRAME(&_hx_pos_0f0f8a6702f060a3_292_outputHelp)
HXLINE( 293)		::Sys_obj::println(HX_("GIT-DEPENDENCY",86,46,b1,a4));
HXLINE( 294)		::Sys_obj::println(HX_("",00,00,00,00));
HXLINE( 295)		::Sys_obj::println(HX_("NAME",4b,3a,c0,33));
HXLINE( 296)		::Sys_obj::println(HX_("    git-dependency - Manages branches as dependencies for complex features.",50,04,2d,8e));
HXLINE( 297)		::Sys_obj::println(HX_("",00,00,00,00));
HXLINE( 298)		::Sys_obj::println(HX_("SYNOPSIS",94,8e,ef,e1));
HXLINE( 299)		::Sys_obj::println(HX_("    git dependency [add|-a <branch>] [delete|-d <branch>] [help|-h]",ec,51,cd,b4));
HXLINE( 300)		::Sys_obj::println(HX_("                   [update <branch> |-u <branch>] [status|-s] [list|-s] [prune|-p]",b4,d4,47,71));
HXLINE( 301)		::Sys_obj::println(HX_("",00,00,00,00));
HXLINE( 302)		::Sys_obj::println(HX_("OPTIONS",3e,07,d2,5f));
HXLINE( 303)		::Sys_obj::println(HX_("    add | -a",17,63,48,60));
HXLINE( 304)		::Sys_obj::println(HX_("        add a branch as a dependency.",d6,0e,f6,e9));
HXLINE( 305)		::Sys_obj::println(HX_("    delete | -d",d0,00,c5,a0));
HXLINE( 306)		::Sys_obj::println(HX_("        remove a branch from the dependency list.",fd,85,9b,c4));
HXLINE( 307)		::Sys_obj::println(HX_("    -help | h",12,6c,f0,8e));
HXLINE( 308)		::Sys_obj::println(HX_("        display help.",ef,99,ba,a6));
HXLINE( 309)		::Sys_obj::println(HX_("    update <branch> | -u <branch>",2b,1e,4b,88));
HXLINE( 310)		::Sys_obj::println(HX_("        attempts to update and pull in dependency. If no branch is supplied it will attempt to pull in all dependencies with an octopus merge. If the merge fails it will fallback to individual merge/conflict resolution.",62,c6,57,06));
HXLINE( 311)		::Sys_obj::println(HX_("    status | -s",78,00,54,7e));
HXLINE( 312)		::Sys_obj::println(HX_("        checks to see if there are any changes between the current HEAD and the branches dependencies and outputs a table with those changes.",3e,9b,29,22));
HXLINE( 313)		::Sys_obj::println(HX_("    list | -l",c5,8b,0e,57));
HXLINE( 314)		::Sys_obj::println(HX_("        list dependencies for the current branch.",ea,fd,b2,27));
HXLINE( 315)		::Sys_obj::println(HX_("    prune | -p",7d,81,be,94));
HXLINE( 316)		::Sys_obj::println(HX_("        prune dependencies from the dependency list that are merged with master.",52,5e,37,df));
            	}


HX_DEFINE_DYNAMIC_FUNC0(App_obj,outputHelp,(void))


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
	HX_MARK_MEMBER_NAME(currentBranch,"currentBranch");
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_END_CLASS();
}

void App_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(dependencyModel,"dependencyModel");
	HX_VISIT_MEMBER_NAME(formatter,"formatter");
	HX_VISIT_MEMBER_NAME(currentBranch,"currentBranch");
	HX_VISIT_MEMBER_NAME(input,"input");
}

hx::Val App_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return hx::Val( run_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { return hx::Val( input ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"formatter") ) { return hx::Val( formatter ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"outputHelp") ) { return hx::Val( outputHelp_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateBranch") ) { return hx::Val( updateBranch_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentBranch") ) { return hx::Val( currentBranch ); }
		if (HX_FIELD_EQ(inName,"addDependency") ) { return hx::Val( addDependency_dyn() ); }
		if (HX_FIELD_EQ(inName,"updateRemotes") ) { return hx::Val( updateRemotes_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"dependencyModel") ) { return hx::Val( dependencyModel ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeDependency") ) { return hx::Val( removeDependency_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"loadCurrentBranch") ) { return hx::Val( loadCurrentBranch_dyn() ); }
		if (HX_FIELD_EQ(inName,"pruneDependencies") ) { return hx::Val( pruneDependencies_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getBranchMergeStatus") ) { return hx::Val( getBranchMergeStatus_dyn() ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getBranchRemoteStatus") ) { return hx::Val( getBranchRemoteStatus_dyn() ); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateDependencyBranch") ) { return hx::Val( updateDependencyBranch_dyn() ); }
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
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast<  ::haxe::io::Input >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"formatter") ) { formatter=inValue.Cast<  ::app::util::Formatter >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentBranch") ) { currentBranch=inValue.Cast< ::String >(); return inValue; }
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
	outFields->push(HX_HCSTRING("currentBranch","\xbb","\x7f","\x75","\xf6"));
	outFields->push(HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo App_obj_sMemberStorageInfo[] = {
	{hx::fsObject /*::app::model::DependencyModel*/ ,(int)offsetof(App_obj,dependencyModel),HX_HCSTRING("dependencyModel","\xde","\xfc","\x7e","\xd4")},
	{hx::fsObject /*::app::util::Formatter*/ ,(int)offsetof(App_obj,formatter),HX_HCSTRING("formatter","\x0a","\xeb","\x67","\x19")},
	{hx::fsString,(int)offsetof(App_obj,currentBranch),HX_HCSTRING("currentBranch","\xbb","\x7f","\x75","\xf6")},
	{hx::fsObject /*::haxe::io::Input*/ ,(int)offsetof(App_obj,input),HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *App_obj_sStaticStorageInfo = 0;
#endif

static ::String App_obj_sMemberFields[] = {
	HX_HCSTRING("dependencyModel","\xde","\xfc","\x7e","\xd4"),
	HX_HCSTRING("formatter","\x0a","\xeb","\x67","\x19"),
	HX_HCSTRING("currentBranch","\xbb","\x7f","\x75","\xf6"),
	HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"),
	HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),
	HX_HCSTRING("addDependency","\x4c","\x60","\x12","\x01"),
	HX_HCSTRING("removeDependency","\x2f","\x34","\x72","\x50"),
	HX_HCSTRING("updateDependencyRemotes","\x59","\xcb","\xe2","\x0e"),
	HX_HCSTRING("updateDependencyBranch","\xf6","\xf7","\x6e","\x62"),
	HX_HCSTRING("updateBranch","\x8b","\xa5","\xdc","\x12"),
	HX_HCSTRING("checkDependencyRemoteStatus","\xab","\xa8","\xd8","\x48"),
	HX_HCSTRING("getBranchRemoteStatus","\x50","\xd6","\x5e","\xa1"),
	HX_HCSTRING("getBranchMergeStatus","\x12","\xc7","\xe0","\xfa"),
	HX_HCSTRING("loadCurrentBranch","\xb5","\x55","\x30","\x5a"),
	HX_HCSTRING("updateRemotes","\x24","\x00","\x6d","\xbe"),
	HX_HCSTRING("pruneDependencies","\x33","\xaa","\xe4","\xb4"),
	HX_HCSTRING("outputHelp","\x62","\x82","\xff","\xa6"),
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
