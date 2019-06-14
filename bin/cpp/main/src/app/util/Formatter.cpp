// Generated by Haxe 3.4.7
#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_app_util_Formatter
#include <app/util/Formatter.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_3_new,"app.util.Formatter","new",0x43246b1d,"app.util.Formatter.new","app/util/Formatter.hx",3,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_16_printTable,"app.util.Formatter","printTable",0xad8af384,"app.util.Formatter.printTable","app/util/Formatter.hx",16,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_45_getFormattedRowOutput,"app.util.Formatter","getFormattedRowOutput",0x7f1d3a52,"app.util.Formatter.getFormattedRowOutput","app/util/Formatter.hx",45,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_57_getPadding,"app.util.Formatter","getPadding",0x69f3c6be,"app.util.Formatter.getPadding","app/util/Formatter.hx",57,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_69_getRowColumnByIndex,"app.util.Formatter","getRowColumnByIndex",0x951adc7e,"app.util.Formatter.getRowColumnByIndex","app/util/Formatter.hx",69,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_80_getLongestStringLength,"app.util.Formatter","getLongestStringLength",0x13684c6e,"app.util.Formatter.getLongestStringLength","app/util/Formatter.hx",80,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_93_setColumnWidths,"app.util.Formatter","setColumnWidths",0x329e2c22,"app.util.Formatter.setColumnWidths","app/util/Formatter.hx",93,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_102_validateColumnCount,"app.util.Formatter","validateColumnCount",0xc63b85e0,"app.util.Formatter.validateColumnCount","app/util/Formatter.hx",102,0xfee69353)
HX_LOCAL_STACK_FRAME(_hx_pos_a23cfafd8c1a025c_4_boot,"app.util.Formatter","boot",0x74d24ed5,"app.util.Formatter.boot","app/util/Formatter.hx",4,0xfee69353)
namespace app{
namespace util{

void Formatter_obj::__construct(hx::Null< bool >  __o_displayColor){
bool displayColor = __o_displayColor.Default(false);
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_3_new)
HXLINE(   7)		this->_columnData = ::Array_obj< int >::__new(0);
HXLINE(  12)		this->_displayColor = displayColor;
            	}

Dynamic Formatter_obj::__CreateEmpty() { return new Formatter_obj; }

void *Formatter_obj::_hx_vtable = 0;

Dynamic Formatter_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< Formatter_obj > _hx_result = new Formatter_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Formatter_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x656c714b;
}

void Formatter_obj::printTable(::Array< ::String > headers,::Array< ::Dynamic> rows){
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_16_printTable)
HXLINE(  17)		if ((this->validateColumnCount(headers,rows) == false)) {
HXLINE(  18)			::Sys_obj::println(HX_("Each Row's column count must match the header count.",53,1f,18,a6));
HXLINE(  19)			return;
            		}
HXLINE(  23)		this->setColumnWidths(headers,rows);
HXLINE(  25)		::Array< ::String > formattedRows = ::Array_obj< ::String >::__new(0);
HXLINE(  26)		::Array< ::String > _g = ::Array_obj< ::String >::__new(0);
HXDLIN(  26)		{
HXLINE(  26)			int _g1 = (int)0;
HXDLIN(  26)			while((_g1 < headers->length)){
HXLINE(  26)				::String h = headers->__get(_g1);
HXDLIN(  26)				_g1 = (_g1 + (int)1);
HXDLIN(  26)				_g->push(h.toUpperCase());
            			}
            		}
HXDLIN(  26)		::String formattedHeaders = this->getFormattedRowOutput(_g);
HXLINE(  27)		::Array< ::String > _g11 = ::Array_obj< ::String >::__new(0);
HXDLIN(  27)		{
HXLINE(  27)			int _g3 = (int)0;
HXDLIN(  27)			int _g2 = formattedHeaders.length;
HXDLIN(  27)			while((_g3 < _g2)){
HXLINE(  27)				_g3 = (_g3 + (int)1);
HXDLIN(  27)				int i = (_g3 - (int)1);
HXDLIN(  27)				_g11->push(HX_("-",2d,00,00,00));
            			}
            		}
HXDLIN(  27)		::String divider = _g11->join(HX_("",00,00,00,00));
HXLINE(  29)		formattedRows->push(divider);
HXLINE(  30)		formattedRows->push(formattedHeaders);
HXLINE(  31)		formattedRows->push(divider);
HXLINE(  33)		{
HXLINE(  33)			int _g21 = (int)0;
HXDLIN(  33)			while((_g21 < rows->length)){
HXLINE(  33)				::Array< ::String > row = rows->__get(_g21).StaticCast< ::Array< ::String > >();
HXDLIN(  33)				_g21 = (_g21 + (int)1);
HXLINE(  34)				formattedRows->push(this->getFormattedRowOutput(row));
            			}
            		}
HXLINE(  37)		formattedRows->push(divider);
HXLINE(  39)		{
HXLINE(  39)			int _g22 = (int)0;
HXDLIN(  39)			while((_g22 < formattedRows->length)){
HXLINE(  39)				::String formattedRow = formattedRows->__get(_g22);
HXDLIN(  39)				_g22 = (_g22 + (int)1);
HXLINE(  40)				::Sys_obj::println(formattedRow);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Formatter_obj,printTable,(void))

::String Formatter_obj::getFormattedRowOutput(::Array< ::String > row){
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_45_getFormattedRowOutput)
HXLINE(  46)		::Array< ::String > formattedStringArray = ::Array_obj< ::String >::__new(0);
HXLINE(  47)		{
HXLINE(  47)			int _g1 = (int)0;
HXDLIN(  47)			int _g = row->length;
HXDLIN(  47)			while((_g1 < _g)){
HXLINE(  47)				_g1 = (_g1 + (int)1);
HXDLIN(  47)				int colIndex = (_g1 - (int)1);
HXLINE(  48)				::String formattedString = this->getPadding(null());
HXDLIN(  48)				::String formattedString1 = (formattedString + row->__get(colIndex));
HXDLIN(  48)				int formattedString2 = this->_columnData->__get(colIndex);
HXDLIN(  48)				::String formattedString3 = (formattedString1 + this->getPadding((formattedString2 - (row->__get(colIndex).length + ::app::util::Formatter_obj::CELL_PAD))));
HXLINE(  49)				formattedStringArray->push(formattedString3);
            			}
            		}
HXLINE(  52)		::String formattedRow = formattedStringArray->join(HX_("|",7c,00,00,00));
HXLINE(  53)		return ((HX_("|",7c,00,00,00) + formattedRow) + HX_("|",7c,00,00,00));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Formatter_obj,getFormattedRowOutput,return )

::String Formatter_obj::getPadding( ::Dynamic length){
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_57_getPadding)
HXLINE(  58)		 ::Dynamic padLen;
HXDLIN(  58)		if (hx::IsNotNull( length )) {
HXLINE(  58)			padLen = length;
            		}
            		else {
HXLINE(  58)			padLen = ::app::util::Formatter_obj::CELL_PAD;
            		}
HXLINE(  60)		::String padding = HX_("",00,00,00,00);
HXLINE(  61)		{
HXLINE(  61)			int _g1 = (int)0;
HXDLIN(  61)			int _g = padLen;
HXDLIN(  61)			while((_g1 < _g)){
HXLINE(  61)				_g1 = (_g1 + (int)1);
HXDLIN(  61)				int i = (_g1 - (int)1);
HXLINE(  62)				padding = (padding + HX_(" ",20,00,00,00));
            			}
            		}
HXLINE(  65)		return padding;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Formatter_obj,getPadding,return )

::Array< ::String > Formatter_obj::getRowColumnByIndex(int index,::Array< ::Dynamic> rows){
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_69_getRowColumnByIndex)
HXLINE(  70)		::Array< ::String > column = ::Array_obj< ::String >::__new(0);
HXLINE(  72)		{
HXLINE(  72)			int _g1 = (int)0;
HXDLIN(  72)			int _g = rows->length;
HXDLIN(  72)			while((_g1 < _g)){
HXLINE(  72)				_g1 = (_g1 + (int)1);
HXDLIN(  72)				int i = (_g1 - (int)1);
HXLINE(  73)				column->push(rows->__get(i).StaticCast< ::Array< ::String > >()->__get(index));
            			}
            		}
HXLINE(  76)		return column;
            	}


HX_DEFINE_DYNAMIC_FUNC2(Formatter_obj,getRowColumnByIndex,return )

int Formatter_obj::getLongestStringLength(::Array< ::String > array){
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_80_getLongestStringLength)
HXLINE(  81)		int max = (int)0;
HXLINE(  82)		{
HXLINE(  82)			int _g1 = (int)0;
HXDLIN(  82)			int _g = array->length;
HXDLIN(  82)			while((_g1 < _g)){
HXLINE(  82)				_g1 = (_g1 + (int)1);
HXDLIN(  82)				int i = (_g1 - (int)1);
HXLINE(  83)				if ((array->__get(i).length > max)) {
HXLINE(  84)					max = array->__get(i).length;
            				}
            			}
            		}
HXLINE(  88)		return max;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Formatter_obj,getLongestStringLength,return )

void Formatter_obj::setColumnWidths(::Array< ::String > headers,::Array< ::Dynamic> rows){
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_93_setColumnWidths)
HXDLIN(  93)		int _g1 = (int)0;
HXDLIN(  93)		int _g = headers->length;
HXDLIN(  93)		while((_g1 < _g)){
HXDLIN(  93)			_g1 = (_g1 + (int)1);
HXDLIN(  93)			int colIndex = (_g1 - (int)1);
HXLINE(  94)			::Array< ::String > col = this->getRowColumnByIndex(colIndex,rows);
HXLINE(  95)			int maxRowWidth = this->getLongestStringLength(col);
HXLINE(  96)			int maxWidth;
HXDLIN(  96)			if ((headers->__get(colIndex).length > maxRowWidth)) {
HXLINE(  96)				maxWidth = headers->__get(colIndex).length;
            			}
            			else {
HXLINE(  96)				maxWidth = maxRowWidth;
            			}
HXLINE(  97)			::Array< int > _hx_tmp = this->_columnData;
HXDLIN(  97)			_hx_tmp[colIndex] = (maxWidth + (::app::util::Formatter_obj::CELL_PAD * (int)2));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Formatter_obj,setColumnWidths,(void))

bool Formatter_obj::validateColumnCount(::cpp::VirtualArray headers,::Array< ::Dynamic> rows){
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_102_validateColumnCount)
HXLINE( 103)		int colCount = headers->get_length();
HXLINE( 105)		{
HXLINE( 105)			int _g = (int)0;
HXDLIN( 105)			while((_g < rows->length)){
HXLINE( 105)				::cpp::VirtualArray row = ::cpp::VirtualArray( rows->__get(_g));
HXDLIN( 105)				_g = (_g + (int)1);
HXLINE( 106)				if ((row->get_length() != colCount)) {
HXLINE( 107)					return false;
            				}
            			}
            		}
HXLINE( 111)		return true;
            	}


HX_DEFINE_DYNAMIC_FUNC2(Formatter_obj,validateColumnCount,return )

int Formatter_obj::CELL_PAD;


hx::ObjectPtr< Formatter_obj > Formatter_obj::__new(hx::Null< bool >  __o_displayColor) {
	hx::ObjectPtr< Formatter_obj > __this = new Formatter_obj();
	__this->__construct(__o_displayColor);
	return __this;
}

hx::ObjectPtr< Formatter_obj > Formatter_obj::__alloc(hx::Ctx *_hx_ctx,hx::Null< bool >  __o_displayColor) {
	Formatter_obj *__this = (Formatter_obj*)(hx::Ctx::alloc(_hx_ctx, sizeof(Formatter_obj), true, "app.util.Formatter"));
	*(void **)__this = Formatter_obj::_hx_vtable;
	__this->__construct(__o_displayColor);
	return __this;
}

Formatter_obj::Formatter_obj()
{
}

void Formatter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Formatter);
	HX_MARK_MEMBER_NAME(_displayColor,"_displayColor");
	HX_MARK_MEMBER_NAME(_columnData,"_columnData");
	HX_MARK_END_CLASS();
}

void Formatter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_displayColor,"_displayColor");
	HX_VISIT_MEMBER_NAME(_columnData,"_columnData");
}

hx::Val Formatter_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"printTable") ) { return hx::Val( printTable_dyn() ); }
		if (HX_FIELD_EQ(inName,"getPadding") ) { return hx::Val( getPadding_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_columnData") ) { return hx::Val( _columnData ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_displayColor") ) { return hx::Val( _displayColor ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setColumnWidths") ) { return hx::Val( setColumnWidths_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getRowColumnByIndex") ) { return hx::Val( getRowColumnByIndex_dyn() ); }
		if (HX_FIELD_EQ(inName,"validateColumnCount") ) { return hx::Val( validateColumnCount_dyn() ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getFormattedRowOutput") ) { return hx::Val( getFormattedRowOutput_dyn() ); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getLongestStringLength") ) { return hx::Val( getLongestStringLength_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Formatter_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"CELL_PAD") ) { outValue = ( CELL_PAD ); return true; }
	}
	return false;
}

hx::Val Formatter_obj::__SetField(const ::String &inName,const hx::Val &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"_columnData") ) { _columnData=inValue.Cast< ::Array< int > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_displayColor") ) { _displayColor=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Formatter_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"CELL_PAD") ) { CELL_PAD=ioValue.Cast< int >(); return true; }
	}
	return false;
}

void Formatter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("_displayColor","\xa0","\xda","\x23","\x39"));
	outFields->push(HX_HCSTRING("_columnData","\x3f","\xc1","\xd0","\xe0"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo Formatter_obj_sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Formatter_obj,_displayColor),HX_HCSTRING("_displayColor","\xa0","\xda","\x23","\x39")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Formatter_obj,_columnData),HX_HCSTRING("_columnData","\x3f","\xc1","\xd0","\xe0")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo Formatter_obj_sStaticStorageInfo[] = {
	{hx::fsInt,(void *) &Formatter_obj::CELL_PAD,HX_HCSTRING("CELL_PAD","\xd6","\x94","\x18","\x92")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String Formatter_obj_sMemberFields[] = {
	HX_HCSTRING("_displayColor","\xa0","\xda","\x23","\x39"),
	HX_HCSTRING("_columnData","\x3f","\xc1","\xd0","\xe0"),
	HX_HCSTRING("printTable","\xa1","\x0c","\x76","\x63"),
	HX_HCSTRING("getFormattedRowOutput","\x55","\x2c","\x76","\xaf"),
	HX_HCSTRING("getPadding","\xdb","\xdf","\xde","\x1f"),
	HX_HCSTRING("getRowColumnByIndex","\xc1","\x37","\xf4","\x57"),
	HX_HCSTRING("getLongestStringLength","\x0b","\x1d","\xe3","\x30"),
	HX_HCSTRING("setColumnWidths","\xe5","\xe9","\x31","\xad"),
	HX_HCSTRING("validateColumnCount","\x23","\xe1","\x14","\x89"),
	::String(null()) };

static void Formatter_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Formatter_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Formatter_obj::CELL_PAD,"CELL_PAD");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Formatter_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Formatter_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Formatter_obj::CELL_PAD,"CELL_PAD");
};

#endif

hx::Class Formatter_obj::__mClass;

static ::String Formatter_obj_sStaticFields[] = {
	HX_HCSTRING("CELL_PAD","\xd6","\x94","\x18","\x92"),
	::String(null())
};

void Formatter_obj::__register()
{
	hx::Object *dummy = new Formatter_obj;
	Formatter_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("app.util.Formatter","\xab","\x98","\x37","\x5f");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Formatter_obj::__GetStatic;
	__mClass->mSetStaticField = &Formatter_obj::__SetStatic;
	__mClass->mMarkFunc = Formatter_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(Formatter_obj_sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(Formatter_obj_sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Formatter_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Formatter_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Formatter_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Formatter_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Formatter_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_a23cfafd8c1a025c_4_boot)
HXDLIN(   4)		CELL_PAD = (int)2;
            	}
}

} // end namespace app
} // end namespace util