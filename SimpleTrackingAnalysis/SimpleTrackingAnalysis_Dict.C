//
// File generated by rootcint at Tue Jul  3 09:28:50 2018

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME SimpleTrackingAnalysis_Dict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "SimpleTrackingAnalysis_Dict.h"

#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// Direct notice to TROOT of the dictionary's loading.
namespace {
   static struct DictInit {
      DictInit() {
         ROOT::RegisterModule();
      }
   } __TheDictionaryInitializer;
}

// START OF SHADOWS

namespace ROOTShadow {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOTShadow
// END OF SHADOWS

namespace ROOTDict {
   void SimpleTrackingAnalysis_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void SimpleTrackingAnalysis_Dictionary();
   static void *new_SimpleTrackingAnalysis(void *p = 0);
   static void *newArray_SimpleTrackingAnalysis(Long_t size, void *p);
   static void delete_SimpleTrackingAnalysis(void *p);
   static void deleteArray_SimpleTrackingAnalysis(void *p);
   static void destruct_SimpleTrackingAnalysis(void *p);

   // Function generating the singleton type initializer
   static ROOT::TGenericClassInfo *GenerateInitInstanceLocal(const ::SimpleTrackingAnalysis*)
   {
      ::SimpleTrackingAnalysis *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SimpleTrackingAnalysis),0);
      static ::ROOT::TGenericClassInfo 
         instance("SimpleTrackingAnalysis", "./SimpleTrackingAnalysis.h", 21,
                  typeid(::SimpleTrackingAnalysis), ::ROOT::DefineBehavior(ptr, ptr),
                  0, &SimpleTrackingAnalysis_Dictionary, isa_proxy, 1,
                  sizeof(::SimpleTrackingAnalysis) );
      instance.SetNew(&new_SimpleTrackingAnalysis);
      instance.SetNewArray(&newArray_SimpleTrackingAnalysis);
      instance.SetDelete(&delete_SimpleTrackingAnalysis);
      instance.SetDeleteArray(&deleteArray_SimpleTrackingAnalysis);
      instance.SetDestructor(&destruct_SimpleTrackingAnalysis);
      return &instance;
   }
   ROOT::TGenericClassInfo *GenerateInitInstance(const ::SimpleTrackingAnalysis*)
   {
      return GenerateInitInstanceLocal((::SimpleTrackingAnalysis*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SimpleTrackingAnalysis*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void SimpleTrackingAnalysis_Dictionary() {
      ::ROOTDict::GenerateInitInstanceLocal((const ::SimpleTrackingAnalysis*)0x0)->GetClass();
   }

} // end of namespace ROOTDict

namespace ROOTDict {
   // Wrappers around operator new
   static void *new_SimpleTrackingAnalysis(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SimpleTrackingAnalysis : new ::SimpleTrackingAnalysis;
   }
   static void *newArray_SimpleTrackingAnalysis(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SimpleTrackingAnalysis[nElements] : new ::SimpleTrackingAnalysis[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimpleTrackingAnalysis(void *p) {
      delete ((::SimpleTrackingAnalysis*)p);
   }
   static void deleteArray_SimpleTrackingAnalysis(void *p) {
      delete [] ((::SimpleTrackingAnalysis*)p);
   }
   static void destruct_SimpleTrackingAnalysis(void *p) {
      typedef ::SimpleTrackingAnalysis current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOTDict for class ::SimpleTrackingAnalysis

/********************************************************
* SimpleTrackingAnalysis_Dict.C
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableSimpleTrackingAnalysis_Dict();

extern "C" void G__set_cpp_environmentSimpleTrackingAnalysis_Dict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("SimpleTrackingAnalysis.h");
  G__cpp_reset_tagtableSimpleTrackingAnalysis_Dict();
}
#include <new>
extern "C" int G__cpp_dllrevSimpleTrackingAnalysis_Dict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* SimpleTrackingAnalysis */
static int G__SimpleTrackingAnalysis_Dict_194_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   SimpleTrackingAnalysis* p = NULL;
   char* gvp = (char*) G__getgvp();
   switch (libp->paran) {
   case 1:
     //m: 1
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new SimpleTrackingAnalysis(*(string*) libp->para[0].ref);
     } else {
       p = new((void*) gvp) SimpleTrackingAnalysis(*(string*) libp->para[0].ref);
     }
     break;
   case 0:
     int n = G__getaryconstruct();
     if (n) {
       if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
         p = new SimpleTrackingAnalysis[n];
       } else {
         p = new((void*) gvp) SimpleTrackingAnalysis[n];
       }
     } else {
       if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
         p = new SimpleTrackingAnalysis;
       } else {
         p = new((void*) gvp) SimpleTrackingAnalysis;
       }
     }
     break;
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__SimpleTrackingAnalysis_Dict_194_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((SimpleTrackingAnalysis*) G__getstructoffset())->set_nlayers((unsigned int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__SimpleTrackingAnalysis_Dict_194_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((SimpleTrackingAnalysis*) G__getstructoffset())->set_verbosity((int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__SimpleTrackingAnalysis_Dict_194_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   SimpleTrackingAnalysis* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new SimpleTrackingAnalysis(*(SimpleTrackingAnalysis*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef SimpleTrackingAnalysis G__TSimpleTrackingAnalysis;
static int G__SimpleTrackingAnalysis_Dict_194_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 0
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (SimpleTrackingAnalysis*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((SimpleTrackingAnalysis*) (soff+(sizeof(SimpleTrackingAnalysis)*i)))->~G__TSimpleTrackingAnalysis();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (SimpleTrackingAnalysis*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((SimpleTrackingAnalysis*) (soff))->~G__TSimpleTrackingAnalysis();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* SimpleTrackingAnalysis */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncSimpleTrackingAnalysis_Dict {
 public:
  G__Sizep2memfuncSimpleTrackingAnalysis_Dict(): p(&G__Sizep2memfuncSimpleTrackingAnalysis_Dict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncSimpleTrackingAnalysis_Dict::*p)();
};

size_t G__get_sizep2memfuncSimpleTrackingAnalysis_Dict()
{
  G__Sizep2memfuncSimpleTrackingAnalysis_Dict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceSimpleTrackingAnalysis_Dict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis))) {
     SimpleTrackingAnalysis *G__Lderived;
     G__Lderived=(SimpleTrackingAnalysis*)0x1000;
     {
       SubsysReco *G__Lpbase=(SubsysReco*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis),G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SubsysReco),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
     {
       Fun4AllBase *G__Lpbase=(Fun4AllBase*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis),G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_Fun4AllBase),(long)G__Lpbase-(long)G__Lderived,1,0);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableSimpleTrackingAnalysis_Dict() {

   /* Setting up typedef entry */
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* SimpleTrackingAnalysis */
static void G__setup_memvarSimpleTrackingAnalysis(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis));
   { SimpleTrackingAnalysis *p; p=(SimpleTrackingAnalysis*)0x1000; if (p) { }
   G__memvar_setup((void*)0,100,0,1,-1,-1,-1,4,"emc_radius_inner=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,1,-1,-1,-1,4,"hci_radius_inner=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,1,-1,-1,-1,4,"hco_radius_inner=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,1,-1,-1,-1,4,"emc_radius_outer=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,1,-1,-1,-1,4,"hci_radius_outer=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,1,-1,-1,-1,4,"hco_radius_outer=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"magneticfield=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"verbosity=",0,(char*)NULL);
   G__memvar_setup((void*)0,109,0,0,-1,-1,-1,4,"nevents=",0,(char*)NULL);
   G__memvar_setup((void*)0,109,0,0,-1,-1,-1,4,"nerrors=",0,(char*)NULL);
   G__memvar_setup((void*)0,109,0,0,-1,-1,-1,4,"nwarnings=",0,(char*)NULL);
   G__memvar_setup((void*)0,104,0,0,-1,-1,-1,4,"nlayers=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"_recopt_quality=",0,"quality distributions");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"_recopt_quality_tracks_all=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"_recopt_quality_tracks_recoWithin4Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"_truept_quality_particles_recoWithin4Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"_truept_dca=",0,"dca resolution");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"_truept_dptoverpt=",0,"momentum resolution");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_truept_particles_leavingAllHits=",0,"pattern reco eff baseline");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_truept_particles_recoWithExactHits=",0,"pattern reco eff by nhits");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_truept_particles_recoWithin1Hit=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_truept_particles_recoWithin2Hits=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_truept_particles_recoWithin3Percent=",0,"parttern reco eff by momentum match");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_truept_particles_recoWithin4Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_truept_particles_recoWithin5Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_recopt_tracks_all=",0,"purity baseline (non-embedded particles)");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_recopt_tracks_recoWithExactHits=",0,"purity by nhit match");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_recopt_tracks_recoWithin1Hit=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_recopt_tracks_recoWithin2Hits=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_recopt_tracks_recoWithin3Percent=",0,"purity by momentum match");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_recopt_tracks_recoWithin4Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_recopt_tracks_recoWithin5Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_all=",0,"purity baseline (non-embedded particles)");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithExactHits=",0,"purity by nhit match");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin1Hit=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin2Hits=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin3Percent=",0,"purity by momentum match");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin4Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin5Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin1Sigma=",0,"purity by momentum match");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin2Sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_recopt_tracks_withcalocuts_recoWithin3Sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_leavingAllHits=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithExactHits=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin1Hit=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin2Hits=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin3Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin4Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin5Percent=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin1Sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin2Sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_truept_particles_withcalocuts_recoWithin3Sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits8=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits7=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits6=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits5=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits4=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits3=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits2=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_nhits1=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_pt1sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_pt2sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_pt3sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_pt4sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_pt5sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_reco_calo_pt6sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits8=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits7=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits6=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits5=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits4=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits3=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits2=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_nhits1=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_pt1sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_pt2sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_pt3sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_pt4sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_pt5sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH2D),-1,-1,4,"th2d_true_calo_pt6sigma=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_dx_vertex=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_dy_vertex=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"_dz_vertex=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"hmult=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_TH1D),-1,-1,4,"hmult_vertex=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarSimpleTrackingAnalysis_Dict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncSimpleTrackingAnalysis(void) {
   /* SimpleTrackingAnalysis */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis));
   G__memfunc_setup("SimpleTrackingAnalysis",2273,G__SimpleTrackingAnalysis_Dict_194_0_1, 105, G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis), -1, 0, 1, 1, 1, 0, "u 'string' - 11 '\"SimpleTrackingAnalysis\"' name", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Init",404,(G__InterfaceMethod) NULL,105, -1, -1, 0, 1, 1, 1, 0, "U 'PHCompositeNode' - 0 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("process_event",1408,(G__InterfaceMethod) NULL,105, -1, -1, 0, 1, 1, 1, 0, "U 'PHCompositeNode' - 0 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("End",279,(G__InterfaceMethod) NULL,105, -1, -1, 0, 1, 1, 1, 0, "U 'PHCompositeNode' - 0 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("set_nlayers",1193,G__SimpleTrackingAnalysis_Dict_194_0_5, 121, -1, -1, 0, 1, 1, 1, 0, "h - - 0 - x", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("set_verbosity",1426,G__SimpleTrackingAnalysis_Dict_194_0_6, 121, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - x", (char*)NULL, (void*) NULL, 0);
   // automatic copy constructor
   G__memfunc_setup("SimpleTrackingAnalysis", 2273, G__SimpleTrackingAnalysis_Dict_194_0_7, (int) ('i'), 
G__get_linked_tagnum(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis), -1, 0, 1, 1, 1, 0, "u 'SimpleTrackingAnalysis' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~SimpleTrackingAnalysis", 2399, G__SimpleTrackingAnalysis_Dict_194_0_8, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncSimpleTrackingAnalysis_Dict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {
}

static void G__cpp_setup_global2() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalSimpleTrackingAnalysis_Dict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
  G__cpp_setup_global2();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {
}

static void G__cpp_setup_func13() {
}

static void G__cpp_setup_func14() {
}

static void G__cpp_setup_func15() {
}

static void G__cpp_setup_func16() {
}

static void G__cpp_setup_func17() {
}

static void G__cpp_setup_func18() {
}

static void G__cpp_setup_func19() {
}

static void G__cpp_setup_func20() {
}

static void G__cpp_setup_func21() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcSimpleTrackingAnalysis_Dict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
  G__cpp_setup_func13();
  G__cpp_setup_func14();
  G__cpp_setup_func15();
  G__cpp_setup_func16();
  G__cpp_setup_func17();
  G__cpp_setup_func18();
  G__cpp_setup_func19();
  G__cpp_setup_func20();
  G__cpp_setup_func21();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_string = { "string" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_Fun4AllBase = { "Fun4AllBase" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_PHCompositeNode = { "PHCompositeNode" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_SubsysReco = { "SubsysReco" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_TH1D = { "TH1D" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_TH2D = { "TH2D" , 99 , -1 };
G__linked_taginfo G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis = { "SimpleTrackingAnalysis" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableSimpleTrackingAnalysis_Dict() {
  G__SimpleTrackingAnalysis_DictLN_string.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_Fun4AllBase.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_PHCompositeNode.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_SubsysReco.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_TH1D.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_TH2D.tagnum = -1 ;
  G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableSimpleTrackingAnalysis_Dict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_string);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_Fun4AllBase);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_PHCompositeNode);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_SubsysReco);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_TH1D);
   G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_TH2D);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__SimpleTrackingAnalysis_DictLN_SimpleTrackingAnalysis),sizeof(SimpleTrackingAnalysis),-1,65792,(char*)NULL,G__setup_memvarSimpleTrackingAnalysis,G__setup_memfuncSimpleTrackingAnalysis);
}
extern "C" void G__cpp_setupSimpleTrackingAnalysis_Dict(void) {
  G__check_setup_version(30051515,"G__cpp_setupSimpleTrackingAnalysis_Dict()");
  G__set_cpp_environmentSimpleTrackingAnalysis_Dict();
  G__cpp_setup_tagtableSimpleTrackingAnalysis_Dict();

  G__cpp_setup_inheritanceSimpleTrackingAnalysis_Dict();

  G__cpp_setup_typetableSimpleTrackingAnalysis_Dict();

  G__cpp_setup_memvarSimpleTrackingAnalysis_Dict();

  G__cpp_setup_memfuncSimpleTrackingAnalysis_Dict();
  G__cpp_setup_globalSimpleTrackingAnalysis_Dict();
  G__cpp_setup_funcSimpleTrackingAnalysis_Dict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncSimpleTrackingAnalysis_Dict();
  return;
}
class G__cpp_setup_initSimpleTrackingAnalysis_Dict {
  public:
    G__cpp_setup_initSimpleTrackingAnalysis_Dict() { G__add_setup_func("SimpleTrackingAnalysis_Dict",(G__incsetup)(&G__cpp_setupSimpleTrackingAnalysis_Dict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initSimpleTrackingAnalysis_Dict() { G__remove_setup_func("SimpleTrackingAnalysis_Dict"); }
};
G__cpp_setup_initSimpleTrackingAnalysis_Dict G__cpp_setup_initializerSimpleTrackingAnalysis_Dict;

