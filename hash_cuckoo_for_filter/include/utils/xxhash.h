

#if defined (__cplusplus)
extern "C" {
#endif


#ifdef XXH_DOXYGEN

#  define XXH_INLINE_ALL
#  undef XXH_INLINE_ALL

#  define XXH_PRIVATE_API
#  undef XXH_PRIVATE_API

#  define XXH_NAMESPACE 
#  undef XXH_NAMESPACE
#endif

#if (defined(XXH_INLINE_ALL) || defined(XXH_PRIVATE_API)) \
 && !defined(XXH_INLINE_ALL_31684351384)

#  define XXH_INLINE_ALL_31684351384
   
#  undef XXH_STATIC_LINKING_ONLY   
#  define XXH_STATIC_LINKING_ONLY
   
#  undef XXH_PUBLIC_API
#  if defined(__GNUC__)
#    define XXH_PUBLIC_API static __inline __attribute__((unused))
#  elif defined (__cplusplus) || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) )
#    define XXH_PUBLIC_API static inline
#  elif defined(_MSC_VER)
#    define XXH_PUBLIC_API static __inline
#  else
     
#    define XXH_PUBLIC_API static
#  endif

   
   
#  undef XXH_versionNumber
    
#  undef XXH32
#  undef XXH32_createState
#  undef XXH32_freeState
#  undef XXH32_reset
#  undef XXH32_update
#  undef XXH32_digest
#  undef XXH32_copyState
#  undef XXH32_canonicalFromHash
#  undef XXH32_hashFromCanonical
    
#  undef XXH64
#  undef XXH64_createState
#  undef XXH64_freeState
#  undef XXH64_reset
#  undef XXH64_update
#  undef XXH64_digest
#  undef XXH64_copyState
#  undef XXH64_canonicalFromHash
#  undef XXH64_hashFromCanonical
    
#  undef XXH3_64bits
#  undef XXH3_64bits_withSecret
#  undef XXH3_64bits_withSeed
#  undef XXH3_64bits_withSecretandSeed
#  undef XXH3_createState
#  undef XXH3_freeState
#  undef XXH3_copyState
#  undef XXH3_64bits_reset
#  undef XXH3_64bits_reset_withSeed
#  undef XXH3_64bits_reset_withSecret
#  undef XXH3_64bits_update
#  undef XXH3_64bits_digest
#  undef XXH3_generateSecret
    
#  undef XXH128
#  undef XXH3_128bits
#  undef XXH3_128bits_withSeed
#  undef XXH3_128bits_withSecret
#  undef XXH3_128bits_reset
#  undef XXH3_128bits_reset_withSeed
#  undef XXH3_128bits_reset_withSecret
#  undef XXH3_128bits_reset_withSecretandSeed
#  undef XXH3_128bits_update
#  undef XXH3_128bits_digest
#  undef XXH128_isEqual
#  undef XXH128_cmp
#  undef XXH128_canonicalFromHash
#  undef XXH128_hashFromCanonical
    
#  undef XXH_NAMESPACE

    
#  define XXH_NAMESPACE XXH_INLINE_
   
#  define XXH_IPREF(Id)   XXH_NAMESPACE ## Id
#  define XXH_OK XXH_IPREF(XXH_OK)
#  define XXH_ERROR XXH_IPREF(XXH_ERROR)
#  define XXH_errorcode XXH_IPREF(XXH_errorcode)
#  define XXH32_canonical_t  XXH_IPREF(XXH32_canonical_t)
#  define XXH64_canonical_t  XXH_IPREF(XXH64_canonical_t)
#  define XXH128_canonical_t XXH_IPREF(XXH128_canonical_t)
#  define XXH32_state_s XXH_IPREF(XXH32_state_s)
#  define XXH32_state_t XXH_IPREF(XXH32_state_t)
#  define XXH64_state_s XXH_IPREF(XXH64_state_s)
#  define XXH64_state_t XXH_IPREF(XXH64_state_t)
#  define XXH3_state_s  XXH_IPREF(XXH3_state_s)
#  define XXH3_state_t  XXH_IPREF(XXH3_state_t)
#  define XXH128_hash_t XXH_IPREF(XXH128_hash_t)
   
#  undef XXHASH_H_5627135585666179
#  undef XXHASH_H_STATIC_13879238742
#endif


#ifndef XXHASH_H_5627135585666179
#define XXHASH_H_5627135585666179 1


#if !defined(XXH_INLINE_ALL) && !defined(XXH_PRIVATE_API)
#  if defined(WIN32) && defined(_MSC_VER) && (defined(XXH_IMPORT) || defined(XXH_EXPORT))
#    ifdef XXH_EXPORT
#      define XXH_PUBLIC_API __declspec(dllexport)
#    elif XXH_IMPORT
#      define XXH_PUBLIC_API __declspec(dllimport)
#    endif
#  else
#    define XXH_PUBLIC_API
#  endif
#endif

#ifdef XXH_NAMESPACE
#  define XXH_CAT(A,B) A##B
#  define XXH_NAME2(A,B) XXH_CAT(A,B)
#  define XXH_versionNumber XXH_NAME2(XXH_NAMESPACE, XXH_versionNumber)

#  define XXH32 XXH_NAME2(XXH_NAMESPACE, XXH32)
#  define XXH32_createState XXH_NAME2(XXH_NAMESPACE, XXH32_createState)
#  define XXH32_freeState XXH_NAME2(XXH_NAMESPACE, XXH32_freeState)
#  define XXH32_reset XXH_NAME2(XXH_NAMESPACE, XXH32_reset)
#  define XXH32_update XXH_NAME2(XXH_NAMESPACE, XXH32_update)
#  define XXH32_digest XXH_NAME2(XXH_NAMESPACE, XXH32_digest)
#  define XXH32_copyState XXH_NAME2(XXH_NAMESPACE, XXH32_copyState)
#  define XXH32_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH32_canonicalFromHash)
#  define XXH32_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH32_hashFromCanonical)

#  define XXH64 XXH_NAME2(XXH_NAMESPACE, XXH64)
#  define XXH64_createState XXH_NAME2(XXH_NAMESPACE, XXH64_createState)
#  define XXH64_freeState XXH_NAME2(XXH_NAMESPACE, XXH64_freeState)
#  define XXH64_reset XXH_NAME2(XXH_NAMESPACE, XXH64_reset)
#  define XXH64_update XXH_NAME2(XXH_NAMESPACE, XXH64_update)
#  define XXH64_digest XXH_NAME2(XXH_NAMESPACE, XXH64_digest)
#  define XXH64_copyState XXH_NAME2(XXH_NAMESPACE, XXH64_copyState)
#  define XXH64_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH64_canonicalFromHash)
#  define XXH64_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH64_hashFromCanonical)

#  define XXH3_64bits XXH_NAME2(XXH_NAMESPACE, XXH3_64bits)
#  define XXH3_64bits_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_withSecret)
#  define XXH3_64bits_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_withSeed)
#  define XXH3_64bits_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_withSecretandSeed)
#  define XXH3_createState XXH_NAME2(XXH_NAMESPACE, XXH3_createState)
#  define XXH3_freeState XXH_NAME2(XXH_NAMESPACE, XXH3_freeState)
#  define XXH3_copyState XXH_NAME2(XXH_NAMESPACE, XXH3_copyState)
#  define XXH3_64bits_reset XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset)
#  define XXH3_64bits_reset_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset_withSeed)
#  define XXH3_64bits_reset_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset_withSecret)
#  define XXH3_64bits_reset_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset_withSecretandSeed)
#  define XXH3_64bits_update XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_update)
#  define XXH3_64bits_digest XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_digest)
#  define XXH3_generateSecret XXH_NAME2(XXH_NAMESPACE, XXH3_generateSecret)
#  define XXH3_generateSecret_fromSeed XXH_NAME2(XXH_NAMESPACE, XXH3_generateSecret_fromSeed)

#  define XXH128 XXH_NAME2(XXH_NAMESPACE, XXH128)
#  define XXH3_128bits XXH_NAME2(XXH_NAMESPACE, XXH3_128bits)
#  define XXH3_128bits_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_withSeed)
#  define XXH3_128bits_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_withSecret)
#  define XXH3_128bits_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_withSecretandSeed)
#  define XXH3_128bits_reset XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset)
#  define XXH3_128bits_reset_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset_withSeed)
#  define XXH3_128bits_reset_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset_withSecret)
#  define XXH3_128bits_reset_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset_withSecretandSeed)
#  define XXH3_128bits_update XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_update)
#  define XXH3_128bits_digest XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_digest)
#  define XXH128_isEqual XXH_NAME2(XXH_NAMESPACE, XXH128_isEqual)
#  define XXH128_cmp     XXH_NAME2(XXH_NAMESPACE, XXH128_cmp)
#  define XXH128_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH128_canonicalFromHash)
#  define XXH128_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH128_hashFromCanonical)
#endif


#if !defined(XXH_INLINE_ALL) && !defined(XXH_PRIVATE_API)
#  if defined(WIN32) && defined(_MSC_VER) && (defined(XXH_IMPORT) || defined(XXH_EXPORT))
#    ifdef XXH_EXPORT
#      define XXH_PUBLIC_API __declspec(dllexport)
#    elif XXH_IMPORT
#      define XXH_PUBLIC_API __declspec(dllimport)
#    endif
#  else
#    define XXH_PUBLIC_API
#  endif
#endif

#if defined (__GNUC__)
# define XXH_CONSTF  __attribute__((const))
# define XXH_PUREF   __attribute__((pure))
# define XXH_MALLOCF __attribute__((malloc))
#else
# define XXH_CONSTF  
# define XXH_PUREF
# define XXH_MALLOCF
#endif


#define XXH_VERSION_MAJOR    0
#define XXH_VERSION_MINOR    8
#define XXH_VERSION_RELEASE  1

#define XXH_VERSION_NUMBER  (XXH_VERSION_MAJOR *100*100 + XXH_VERSION_MINOR *100 + XXH_VERSION_RELEASE)


XXH_PUBLIC_API XXH_CONSTF unsigned XXH_versionNumber(void);


#include <stddef.h>

typedef enum {
    XXH_OK = 0,
    XXH_ERROR
} XXH_errorcode;


#if defined(XXH_DOXYGEN)

typedef uint32_t XXH32_hash_t;

#elif !defined (__VMS) \
 && (defined (__cplusplus) \
 || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)))
#   include <stdint.h>
typedef uint32_t XXH32_hash_t;

#else
#   include <limits.h>
#   if UINT_MAX == 0xFFFFFFFFUL
typedef unsigned int XXH32_hash_t;
#   elif ULONG_MAX == 0xFFFFFFFFUL
typedef unsigned long XXH32_hash_t;
#   else
#     error "unsupported platform: need a 32-bit type"
#   endif
#endif


XXH_PUBLIC_API XXH_PUREF XXH32_hash_t XXH32(const void *input, size_t length, XXH32_hash_t seed);

#ifndef XXH_NO_STREAM


typedef struct XXH32_state_s XXH32_state_t;


XXH_PUBLIC_API XXH_MALLOCF XXH32_state_t *XXH32_createState(void);

XXH_PUBLIC_API XXH_errorcode XXH32_freeState(XXH32_state_t *statePtr);

XXH_PUBLIC_API void XXH32_copyState(XXH32_state_t *dst_state, const XXH32_state_t *src_state);


XXH_PUBLIC_API XXH_errorcode XXH32_reset(XXH32_state_t *statePtr, XXH32_hash_t seed);


XXH_PUBLIC_API XXH_errorcode XXH32_update(XXH32_state_t *statePtr, const void *input, size_t length);


XXH_PUBLIC_API XXH_PUREF XXH32_hash_t XXH32_digest(const XXH32_state_t *statePtr);
#endif


typedef struct {
    unsigned char digest[4];
} XXH32_canonical_t;


XXH_PUBLIC_API void XXH32_canonicalFromHash(XXH32_canonical_t *dst, XXH32_hash_t hash);


XXH_PUBLIC_API XXH_PUREF XXH32_hash_t XXH32_hashFromCanonical(const XXH32_canonical_t *src);


#ifdef __has_attribute
# define XXH_HAS_ATTRIBUTE(x) __has_attribute(x)
#else
# define XXH_HAS_ATTRIBUTE(x) 0
#endif


#if defined(__STDC_VERSION__) && (__STDC_VERSION__ > 201710L) && defined(__has_c_attribute)
# define XXH_HAS_C_ATTRIBUTE(x) __has_c_attribute(x)
#else
# define XXH_HAS_C_ATTRIBUTE(x) 0
#endif

#if defined(__cplusplus) && defined(__has_cpp_attribute)
# define XXH_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
# define XXH_HAS_CPP_ATTRIBUTE(x) 0
#endif


#if XXH_HAS_C_ATTRIBUTE(fallthrough) || XXH_HAS_CPP_ATTRIBUTE(fallthrough)
# define XXH_FALLTHROUGH [[fallthrough]]
#elif XXH_HAS_ATTRIBUTE(__fallthrough__)
# define XXH_FALLTHROUGH __attribute__ ((__fallthrough__))
#else
# define XXH_FALLTHROUGH
#endif


#ifndef XXH_NO_LONG_LONG

#if defined(XXH_DOXYGEN)

typedef uint64_t XXH64_hash_t;
#elif !defined (__VMS) \
 && (defined (__cplusplus) \
 || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)))
#  include <stdint.h>
typedef uint64_t XXH64_hash_t;
#else
#  include <limits.h>
#  if defined(__LP64__) && ULONG_MAX == 0xFFFFFFFFFFFFFFFFULL

typedef unsigned long XXH64_hash_t;
#  else

typedef unsigned long long XXH64_hash_t;
#  endif
#endif


XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH64(const void *input, size_t length, XXH64_hash_t seed);


#ifndef XXH_NO_STREAM

typedef struct XXH64_state_s XXH64_state_t;
XXH_PUBLIC_API XXH_MALLOCF XXH64_state_t *XXH64_createState(void);
XXH_PUBLIC_API XXH_errorcode XXH64_freeState(XXH64_state_t *statePtr);
XXH_PUBLIC_API void XXH64_copyState(XXH64_state_t *dst_state, const XXH64_state_t *src_state);

XXH_PUBLIC_API XXH_errorcode XXH64_reset(XXH64_state_t *statePtr, XXH64_hash_t seed);
XXH_PUBLIC_API XXH_errorcode XXH64_update(XXH64_state_t *statePtr, const void *input, size_t length);
XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH64_digest(const XXH64_state_t *statePtr);
#endif

typedef struct {
    unsigned char digest[sizeof(XXH64_hash_t)];
} XXH64_canonical_t;
XXH_PUBLIC_API void XXH64_canonicalFromHash(XXH64_canonical_t *dst, XXH64_hash_t hash);
XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH64_hashFromCanonical(const XXH64_canonical_t *src);

#ifndef XXH_NO_XXH3


XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH3_64bits(const void *input, size_t length);


XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH3_64bits_withSeed(const void *input, size_t length, XXH64_hash_t seed);


#define XXH3_SECRET_SIZE_MIN 136


XXH_PUBLIC_API XXH_PUREF XXH64_hash_t
XXH3_64bits_withSecret(const void *data, size_t len, const void *secret, size_t secretSize);


#ifndef XXH_NO_STREAM


typedef struct XXH3_state_s XXH3_state_t;
XXH_PUBLIC_API XXH_MALLOCF XXH3_state_t *XXH3_createState(void);
XXH_PUBLIC_API XXH_errorcode XXH3_freeState(XXH3_state_t *statePtr);
XXH_PUBLIC_API void XXH3_copyState(XXH3_state_t *dst_state, const XXH3_state_t *src_state);


XXH_PUBLIC_API XXH_errorcode XXH3_64bits_reset(XXH3_state_t *statePtr);

XXH_PUBLIC_API XXH_errorcode XXH3_64bits_reset_withSeed(XXH3_state_t *statePtr, XXH64_hash_t seed);

XXH_PUBLIC_API XXH_errorcode
XXH3_64bits_reset_withSecret(XXH3_state_t *statePtr, const void *secret, size_t secretSize);

XXH_PUBLIC_API XXH_errorcode XXH3_64bits_update(XXH3_state_t *statePtr, const void *input, size_t length);
XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH3_64bits_digest(const XXH3_state_t *statePtr);
#endif


typedef struct {
    XXH64_hash_t low64;
    XXH64_hash_t high64;
} XXH128_hash_t;


XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH3_128bits(const void *data, size_t len);

XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH3_128bits_withSeed(const void *data, size_t len, XXH64_hash_t seed);

XXH_PUBLIC_API XXH_PUREF XXH128_hash_t
XXH3_128bits_withSecret(const void *data, size_t len, const void *secret, size_t secretSize);


#ifndef XXH_NO_STREAM


XXH_PUBLIC_API XXH_errorcode XXH3_128bits_reset(XXH3_state_t *statePtr);
XXH_PUBLIC_API XXH_errorcode XXH3_128bits_reset_withSeed(XXH3_state_t *statePtr, XXH64_hash_t seed);
XXH_PUBLIC_API XXH_errorcode
XXH3_128bits_reset_withSecret(XXH3_state_t *statePtr, const void *secret, size_t secretSize);

XXH_PUBLIC_API XXH_errorcode XXH3_128bits_update(XXH3_state_t *statePtr, const void *input, size_t length);
XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH3_128bits_digest(const XXH3_state_t *statePtr);
#endif


XXH_PUBLIC_API XXH_PUREF int XXH128_isEqual(XXH128_hash_t h1, XXH128_hash_t h2);


XXH_PUBLIC_API XXH_PUREF int XXH128_cmp(const void *h128_1, const void *h128_2);


typedef struct {
    unsigned char digest[sizeof(XXH128_hash_t)];
} XXH128_canonical_t;
XXH_PUBLIC_API void XXH128_canonicalFromHash(XXH128_canonical_t *dst, XXH128_hash_t hash);
XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH128_hashFromCanonical(const XXH128_canonical_t *src);


#endif
#endif


#endif


#if defined(XXH_STATIC_LINKING_ONLY) && !defined(XXHASH_H_STATIC_13879238742)
#define XXHASH_H_STATIC_13879238742





struct XXH32_state_s {
   XXH32_hash_t total_len_32; 
   XXH32_hash_t large_len;    
   XXH32_hash_t v[4];         
   XXH32_hash_t mem32[4];     
   XXH32_hash_t memsize;      
   XXH32_hash_t reserved;     
};   


#ifndef XXH_NO_LONG_LONG  


struct XXH64_state_s {
   XXH64_hash_t total_len;    
   XXH64_hash_t v[4];         
   XXH64_hash_t mem64[4];     
   XXH32_hash_t memsize;      
   XXH32_hash_t reserved32;   
   XXH64_hash_t reserved64;   
};   

#ifndef XXH_NO_XXH3

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) 
#  include <stdalign.h>
#  define XXH_ALIGN(n)      alignas(n)
#elif defined(__cplusplus) && (__cplusplus >= 201103L) 

#  define XXH_ALIGN(n)      alignas(n)
#elif defined(__GNUC__)
#  define XXH_ALIGN(n)      __attribute__ ((aligned(n)))
#elif defined(_MSC_VER)
#  define XXH_ALIGN(n)      __declspec(align(n))
#else
#  define XXH_ALIGN(n)   
#endif


#if !(defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L))    \
    && ! (defined(__cplusplus) && (__cplusplus >= 201103L))  \
    && defined(__GNUC__)
#   define XXH_ALIGN_MEMBER(align, type) type XXH_ALIGN(align)
#else
#   define XXH_ALIGN_MEMBER(align, type) XXH_ALIGN(align) type
#endif


#define XXH3_INTERNALBUFFER_SIZE 256


#define XXH3_SECRET_DEFAULT_SIZE 192


struct XXH3_state_s {
   XXH_ALIGN_MEMBER(64, XXH64_hash_t acc[8]);
       
   XXH_ALIGN_MEMBER(64, unsigned char customSecret[XXH3_SECRET_DEFAULT_SIZE]);
       
   XXH_ALIGN_MEMBER(64, unsigned char buffer[XXH3_INTERNALBUFFER_SIZE]);
       
   XXH32_hash_t bufferedSize;
       
   XXH32_hash_t useSeed;
       
   size_t nbStripesSoFar;
       
   XXH64_hash_t totalLen;
       
   size_t nbStripesPerBlock;
       
   size_t secretLimit;
       
   XXH64_hash_t seed;
       
   XXH64_hash_t reserved64;
       
   const unsigned char* extSecret;
       
   
}; 

#undef XXH_ALIGN_MEMBER


#define XXH3_INITSTATE(XXH3_state_ptr)   { (XXH3_state_ptr)->seed = 0; }



XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH128(const void* data, size_t len, XXH64_hash_t seed);






XXH_PUBLIC_API XXH_errorcode XXH3_generateSecret(void* secretBuffer, size_t secretSize, const void* customSeed, size_t customSeedSize);


XXH_PUBLIC_API void XXH3_generateSecret_fromSeed(void* secretBuffer, XXH64_hash_t seed);


XXH_PUBLIC_API XXH_PUREF XXH64_hash_t
XXH3_64bits_withSecretandSeed(const void* data, size_t len,
                              const void* secret, size_t secretSize,
                              XXH64_hash_t seed);

XXH_PUBLIC_API XXH_PUREF XXH128_hash_t
XXH3_128bits_withSecretandSeed(const void* input, size_t length,
                               const void* secret, size_t secretSize,
                               XXH64_hash_t seed64);
#ifndef XXH_NO_STREAM

XXH_PUBLIC_API XXH_errorcode
XXH3_64bits_reset_withSecretandSeed(XXH3_state_t* statePtr,
                                    const void* secret, size_t secretSize,
                                    XXH64_hash_t seed64);

XXH_PUBLIC_API XXH_errorcode
XXH3_128bits_reset_withSecretandSeed(XXH3_state_t* statePtr,
                                     const void* secret, size_t secretSize,
                                     XXH64_hash_t seed64);
#endif 

#endif  
#endif  
#if defined(XXH_INLINE_ALL) || defined(XXH_PRIVATE_API)
#  define XXH_IMPLEMENTATION
#endif

#endif


#if (defined(XXH_INLINE_ALL) || defined(XXH_PRIVATE_API) \
 || defined(XXH_IMPLEMENTATION)) && !defined(XXH_IMPLEM_13a8737387)
#  define XXH_IMPLEM_13a8737387




#ifdef XXH_DOXYGEN

#  define XXH_NO_LONG_LONG
#  undef XXH_NO_LONG_LONG 

#  define XXH_FORCE_MEMORY_ACCESS 0


#  define XXH_SIZE_OPT 0


#  define XXH_FORCE_ALIGN_CHECK 0


#  define XXH_NO_INLINE_HINTS 0


#  define XXH32_ENDJMP 0


#  define XXH_OLD_NAMES
#  undef XXH_OLD_NAMES 


#  define XXH_NO_STREAM
#  undef XXH_NO_STREAM 
#endif 


#ifndef XXH_FORCE_MEMORY_ACCESS   
   
#  if defined(__GNUC__) && !(defined(__ARM_ARCH) && __ARM_ARCH < 7 && defined(__ARM_FEATURE_UNALIGNED))
#    define XXH_FORCE_MEMORY_ACCESS 1
#  endif
#endif

#ifndef XXH_SIZE_OPT
   
#  if (defined(__GNUC__) || defined(__clang__)) && defined(__OPTIMIZE_SIZE__)
#    define XXH_SIZE_OPT 1
#  else
#    define XXH_SIZE_OPT 0
#  endif
#endif

#ifndef XXH_FORCE_ALIGN_CHECK  
   
#  if XXH_SIZE_OPT >= 1 || \
      defined(__i386)  || defined(__x86_64__) || defined(__aarch64__) || defined(__ARM_FEATURE_UNALIGNED) \
   || defined(_M_IX86) || defined(_M_X64)     || defined(_M_ARM64)    || defined(_M_ARM) 
#    define XXH_FORCE_ALIGN_CHECK 0
#  else
#    define XXH_FORCE_ALIGN_CHECK 1
#  endif
#endif

#ifndef XXH_NO_INLINE_HINTS
#  if XXH_SIZE_OPT >= 1 || defined(__NO_INLINE__)  
#    define XXH_NO_INLINE_HINTS 1
#  else
#    define XXH_NO_INLINE_HINTS 0
#  endif
#endif

#ifndef XXH32_ENDJMP

#  define XXH32_ENDJMP 0
#endif





#if defined(XXH_NO_STREAM)

#elif defined(XXH_NO_STDLIB)



static XXH_CONSTF void* XXH_malloc(size_t s) { (void)s; return NULL; }
static void XXH_free(void* p) { (void)p; }

#else


#include <stdlib.h>


static XXH_MALLOCF void* XXH_malloc(size_t s) { return malloc(s); }


static void XXH_free(void* p) { free(p); }

#endif  

#include <string.h>


static void* XXH_memcpy(void* dest, const void* src, size_t size)
{
    return memcpy(dest,src,size);
}

#include <limits.h>   



#ifdef _MSC_VER 
#  pragma warning(disable : 4127) 
#endif

#if XXH_NO_INLINE_HINTS  
#  if defined(__GNUC__) || defined(__clang__)
#    define XXH_FORCE_INLINE static __attribute__((unused))
#  else
#    define XXH_FORCE_INLINE static
#  endif
#  define XXH_NO_INLINE static

#elif defined(__GNUC__) || defined(__clang__)
#  define XXH_FORCE_INLINE static __inline__ __attribute__((always_inline, unused))
#  define XXH_NO_INLINE static __attribute__((noinline))
#elif defined(_MSC_VER)  
#  define XXH_FORCE_INLINE static __forceinline
#  define XXH_NO_INLINE static __declspec(noinline)
#elif defined (__cplusplus) \
  || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L))   
#  define XXH_FORCE_INLINE static inline
#  define XXH_NO_INLINE static
#else
#  define XXH_FORCE_INLINE static
#  define XXH_NO_INLINE static
#endif





#ifndef XXH_DEBUGLEVEL
#  ifdef DEBUGLEVEL 
#    define XXH_DEBUGLEVEL DEBUGLEVEL
#  else
#    define XXH_DEBUGLEVEL 0
#  endif
#endif

#if (XXH_DEBUGLEVEL>=1)
#  include <assert.h>   
#  define XXH_ASSERT(c)   assert(c)
#else
#  define XXH_ASSERT(c)   ((void)0)
#endif


#ifndef XXH_STATIC_ASSERT
#  if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)    
#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { _Static_assert((c),m); } while(0)
#  elif defined(__cplusplus) && (__cplusplus >= 201103L)            
#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { static_assert((c),m); } while(0)
#  else
#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { struct xxh_sa { char x[(c) ? 1 : -1]; }; } while(0)
#  endif
#  define XXH_STATIC_ASSERT(c) XXH_STATIC_ASSERT_WITH_MESSAGE((c),#c)
#endif


#if defined(__GNUC__) || defined(__clang__)
#  define XXH_COMPILER_GUARD(var) __asm__ __volatile__("" : "+r" (var))
#else
#  define XXH_COMPILER_GUARD(var) ((void)0)
#endif

#if defined(__GNUC__) || defined(__clang__)
#  define XXH_COMPILER_GUARD_W(var) __asm__ __volatile__("" : "+w" (var))
#else
#  define XXH_COMPILER_GUARD_W(var) ((void)0)
#endif


#if !defined (__VMS) \
 && (defined (__cplusplus) \
 || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) ) )
# include <stdint.h>
  typedef uint8_t xxh_u8;
#else
  typedef unsigned char xxh_u8;
#endif
typedef XXH32_hash_t xxh_u32;

#ifdef XXH_OLD_NAMES
#  define BYTE xxh_u8
#  define U8   xxh_u8
#  define U32  xxh_u32
#endif











#if (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==3))

#elif (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==2))


static xxh_u32 XXH_read32(const void* memPtr) { return *(const xxh_u32*) memPtr; }

#elif (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==1))


#ifdef XXH_OLD_NAMES
typedef union { xxh_u32 u32; } __attribute__((packed)) unalign;
#endif
static xxh_u32 XXH_read32(const void* ptr)
{
    typedef __attribute__((aligned(1))) xxh_u32 xxh_unalign32;
    return *((const xxh_unalign32*)ptr);
}

#else


static xxh_u32 XXH_read32(const void* memPtr)
{
    xxh_u32 val;
    XXH_memcpy(&val, memPtr, sizeof(val));
    return val;
}

#endif   





#ifndef XXH_CPU_LITTLE_ENDIAN

#  if defined(_WIN32)  \
     || defined(__LITTLE_ENDIAN__) \
     || (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#    define XXH_CPU_LITTLE_ENDIAN 1
#  elif defined(__BIG_ENDIAN__) \
     || (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#    define XXH_CPU_LITTLE_ENDIAN 0
#  else

static int XXH_isLittleEndian(void)
{
    
    const union { xxh_u32 u; xxh_u8 c[4]; } one = { 1 };
    return one.c[0];
}
#   define XXH_CPU_LITTLE_ENDIAN   XXH_isLittleEndian()
#  endif
#endif





#define XXH_GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)

#ifdef __has_builtin
#  define XXH_HAS_BUILTIN(x) __has_builtin(x)
#else
#  define XXH_HAS_BUILTIN(x) 0
#endif


#if !defined(NO_CLANG_BUILTIN) && XXH_HAS_BUILTIN(__builtin_rotateleft32) \
                               && XXH_HAS_BUILTIN(__builtin_rotateleft64)
#  define XXH_rotl32 __builtin_rotateleft32
#  define XXH_rotl64 __builtin_rotateleft64

#elif defined(_MSC_VER)
#  define XXH_rotl32(x,r) _rotl(x,r)
#  define XXH_rotl64(x,r) _rotl64(x,r)
#else
#  define XXH_rotl32(x,r) (((x) << (r)) | ((x) >> (32 - (r))))
#  define XXH_rotl64(x,r) (((x) << (r)) | ((x) >> (64 - (r))))
#endif


#if defined(_MSC_VER)     
#  define XXH_swap32 _byteswap_ulong
#elif XXH_GCC_VERSION >= 403
#  define XXH_swap32 __builtin_bswap32
#else
static xxh_u32 XXH_swap32 (xxh_u32 x)
{
    return  ((x << 24) & 0xff000000 ) |
            ((x <<  8) & 0x00ff0000 ) |
            ((x >>  8) & 0x0000ff00 ) |
            ((x >> 24) & 0x000000ff );
}
#endif





typedef enum {
    XXH_aligned,  
    XXH_unaligned 
} XXH_alignment;


#if (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==3))

XXH_FORCE_INLINE xxh_u32 XXH_readLE32(const void* memPtr)
{
    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
    return bytePtr[0]
         | ((xxh_u32)bytePtr[1] << 8)
         | ((xxh_u32)bytePtr[2] << 16)
         | ((xxh_u32)bytePtr[3] << 24);
}

XXH_FORCE_INLINE xxh_u32 XXH_readBE32(const void* memPtr)
{
    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
    return bytePtr[3]
         | ((xxh_u32)bytePtr[2] << 8)
         | ((xxh_u32)bytePtr[1] << 16)
         | ((xxh_u32)bytePtr[0] << 24);
}

#else
XXH_FORCE_INLINE xxh_u32 XXH_readLE32(const void* ptr)
{
    return XXH_CPU_LITTLE_ENDIAN ? XXH_read32(ptr) : XXH_swap32(XXH_read32(ptr));
}

static xxh_u32 XXH_readBE32(const void* ptr)
{
    return XXH_CPU_LITTLE_ENDIAN ? XXH_swap32(XXH_read32(ptr)) : XXH_read32(ptr);
}
#endif

XXH_FORCE_INLINE xxh_u32
XXH_readLE32_align(const void* ptr, XXH_alignment align)
{
    if (align==XXH_unaligned) {
        return XXH_readLE32(ptr);
    } else {
        return XXH_CPU_LITTLE_ENDIAN ? *(const xxh_u32*)ptr : XXH_swap32(*(const xxh_u32*)ptr);
    }
}




XXH_PUBLIC_API unsigned XXH_versionNumber (void) { return XXH_VERSION_NUMBER; }




 
#define XXH_PRIME32_1  0x9E3779B1U  
#define XXH_PRIME32_2  0x85EBCA77U  
#define XXH_PRIME32_3  0xC2B2AE3DU  
#define XXH_PRIME32_4  0x27D4EB2FU  
#define XXH_PRIME32_5  0x165667B1U  

#ifdef XXH_OLD_NAMES
#  define PRIME32_1 XXH_PRIME32_1
#  define PRIME32_2 XXH_PRIME32_2
#  define PRIME32_3 XXH_PRIME32_3
#  define PRIME32_4 XXH_PRIME32_4
#  define PRIME32_5 XXH_PRIME32_5
#endif


static xxh_u32 XXH32_round(xxh_u32 acc, xxh_u32 input)
{
    acc += input * XXH_PRIME32_2;
    acc  = XXH_rotl32(acc, 13);
    acc *= XXH_PRIME32_1;
#if (defined(__SSE4_1__) || defined(__aarch64__)) && !defined(XXH_ENABLE_AUTOVECTORIZE)
    
    XXH_COMPILER_GUARD(acc);
#endif
    return acc;
}


static xxh_u32 XXH32_avalanche(xxh_u32 hash)
{
    hash ^= hash >> 15;
    hash *= XXH_PRIME32_2;
    hash ^= hash >> 13;
    hash *= XXH_PRIME32_3;
    hash ^= hash >> 16;
    return hash;
}

#define XXH_get32bits(p) XXH_readLE32_align(p, align)


static XXH_PUREF xxh_u32
XXH32_finalize(xxh_u32 hash, const xxh_u8* ptr, size_t len, XXH_alignment align)
{
#define XXH_PROCESS1 do {                             \
    hash += (*ptr++) * XXH_PRIME32_5;                 \
    hash = XXH_rotl32(hash, 11) * XXH_PRIME32_1;      \
} while (0)

#define XXH_PROCESS4 do {                             \
    hash += XXH_get32bits(ptr) * XXH_PRIME32_3;       \
    ptr += 4;                                         \
    hash  = XXH_rotl32(hash, 17) * XXH_PRIME32_4;     \
} while (0)

    if (ptr==NULL) XXH_ASSERT(len == 0);

    
    if (!XXH32_ENDJMP) {
        len &= 15;
        while (len >= 4) {
            XXH_PROCESS4;
            len -= 4;
        }
        while (len > 0) {
            XXH_PROCESS1;
            --len;
        }
        return XXH32_avalanche(hash);
    } else {
         switch(len&15)  {
           case 12:      XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 8:       XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 4:       XXH_PROCESS4;
                         return XXH32_avalanche(hash);

           case 13:      XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 9:       XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 5:       XXH_PROCESS4;
                         XXH_PROCESS1;
                         return XXH32_avalanche(hash);

           case 14:      XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 10:      XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 6:       XXH_PROCESS4;
                         XXH_PROCESS1;
                         XXH_PROCESS1;
                         return XXH32_avalanche(hash);

           case 15:      XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 11:      XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 7:       XXH_PROCESS4;
                         XXH_FALLTHROUGH;  
           case 3:       XXH_PROCESS1;
                         XXH_FALLTHROUGH;  
           case 2:       XXH_PROCESS1;
                         XXH_FALLTHROUGH;  
           case 1:       XXH_PROCESS1;
                         XXH_FALLTHROUGH;  
           case 0:       return XXH32_avalanche(hash);
        }
        XXH_ASSERT(0);
        return hash;   
    }
}

#ifdef XXH_OLD_NAMES
#  define PROCESS1 XXH_PROCESS1
#  define PROCESS4 XXH_PROCESS4
#else
#  undef XXH_PROCESS1
#  undef XXH_PROCESS4
#endif


XXH_FORCE_INLINE XXH_PUREF xxh_u32
XXH32_endian_align(const xxh_u8* input, size_t len, xxh_u32 seed, XXH_alignment align)
{
    xxh_u32 h32;

    if (input==NULL) XXH_ASSERT(len == 0);

    if (len>=16) {
        const xxh_u8* const bEnd = input + len;
        const xxh_u8* const limit = bEnd - 15;
        xxh_u32 v1 = seed + XXH_PRIME32_1 + XXH_PRIME32_2;
        xxh_u32 v2 = seed + XXH_PRIME32_2;
        xxh_u32 v3 = seed + 0;
        xxh_u32 v4 = seed - XXH_PRIME32_1;

        do {
            v1 = XXH32_round(v1, XXH_get32bits(input)); input += 4;
            v2 = XXH32_round(v2, XXH_get32bits(input)); input += 4;
            v3 = XXH32_round(v3, XXH_get32bits(input)); input += 4;
            v4 = XXH32_round(v4, XXH_get32bits(input)); input += 4;
        } while (input < limit);

        h32 = XXH_rotl32(v1, 1)  + XXH_rotl32(v2, 7)
            + XXH_rotl32(v3, 12) + XXH_rotl32(v4, 18);
    } else {
        h32  = seed + XXH_PRIME32_5;
    }

    h32 += (xxh_u32)len;

    return XXH32_finalize(h32, input, len&15, align);
}


XXH_PUBLIC_API XXH32_hash_t XXH32 (const void* input, size_t len, XXH32_hash_t seed)
{
#if !defined(XXH_NO_STREAM) && XXH_SIZE_OPT >= 2
    
    XXH32_state_t state;
    XXH32_reset(&state, seed);
    XXH32_update(&state, (const xxh_u8*)input, len);
    return XXH32_digest(&state);
#else
    if (XXH_FORCE_ALIGN_CHECK) {
        if ((((size_t)input) & 3) == 0) {   
            return XXH32_endian_align((const xxh_u8*)input, len, seed, XXH_aligned);
    }   }

    return XXH32_endian_align((const xxh_u8*)input, len, seed, XXH_unaligned);
#endif
}




#ifndef XXH_NO_STREAM

XXH_PUBLIC_API XXH32_state_t* XXH32_createState(void)
{
    return (XXH32_state_t*)XXH_malloc(sizeof(XXH32_state_t));
}

XXH_PUBLIC_API XXH_errorcode XXH32_freeState(XXH32_state_t* statePtr)
{
    XXH_free(statePtr);
    return XXH_OK;
}


XXH_PUBLIC_API void XXH32_copyState(XXH32_state_t* dstState, const XXH32_state_t* srcState)
{
    XXH_memcpy(dstState, srcState, sizeof(*dstState));
}


XXH_PUBLIC_API XXH_errorcode XXH32_reset(XXH32_state_t* statePtr, XXH32_hash_t seed)
{
    XXH_ASSERT(statePtr != NULL);
    memset(statePtr, 0, sizeof(*statePtr));
    statePtr->v[0] = seed + XXH_PRIME32_1 + XXH_PRIME32_2;
    statePtr->v[1] = seed + XXH_PRIME32_2;
    statePtr->v[2] = seed + 0;
    statePtr->v[3] = seed - XXH_PRIME32_1;
    return XXH_OK;
}



XXH_PUBLIC_API XXH_errorcode
XXH32_update(XXH32_state_t* state, const void* input, size_t len)
{
    if (input==NULL) {
        XXH_ASSERT(len == 0);
        return XXH_OK;
    }

    {   const xxh_u8* p = (const xxh_u8*)input;
        const xxh_u8* const bEnd = p + len;

        state->total_len_32 += (XXH32_hash_t)len;
        state->large_len |= (XXH32_hash_t)((len>=16) | (state->total_len_32>=16));

        if (state->memsize + len < 16)  {   
            XXH_memcpy((xxh_u8*)(state->mem32) + state->memsize, input, len);
            state->memsize += (XXH32_hash_t)len;
            return XXH_OK;
        }

        if (state->memsize) {   
            XXH_memcpy((xxh_u8*)(state->mem32) + state->memsize, input, 16-state->memsize);
            {   const xxh_u32* p32 = state->mem32;
                state->v[0] = XXH32_round(state->v[0], XXH_readLE32(p32)); p32++;
                state->v[1] = XXH32_round(state->v[1], XXH_readLE32(p32)); p32++;
                state->v[2] = XXH32_round(state->v[2], XXH_readLE32(p32)); p32++;
                state->v[3] = XXH32_round(state->v[3], XXH_readLE32(p32));
            }
            p += 16-state->memsize;
            state->memsize = 0;
        }

        if (p <= bEnd-16) {
            const xxh_u8* const limit = bEnd - 16;

            do {
                state->v[0] = XXH32_round(state->v[0], XXH_readLE32(p)); p+=4;
                state->v[1] = XXH32_round(state->v[1], XXH_readLE32(p)); p+=4;
                state->v[2] = XXH32_round(state->v[2], XXH_readLE32(p)); p+=4;
                state->v[3] = XXH32_round(state->v[3], XXH_readLE32(p)); p+=4;
            } while (p<=limit);

        }

        if (p < bEnd) {
            XXH_memcpy(state->mem32, p, (size_t)(bEnd-p));
            state->memsize = (unsigned)(bEnd-p);
        }
    }

    return XXH_OK;
}



XXH_PUBLIC_API XXH32_hash_t XXH32_digest(const XXH32_state_t* state)
{
    xxh_u32 h32;

    if (state->large_len) {
        h32 = XXH_rotl32(state->v[0], 1)
            + XXH_rotl32(state->v[1], 7)
            + XXH_rotl32(state->v[2], 12)
            + XXH_rotl32(state->v[3], 18);
    } else {
        h32 = state->v[2]  + XXH_PRIME32_5;
    }

    h32 += state->total_len_32;

    return XXH32_finalize(h32, (const xxh_u8*)state->mem32, state->memsize, XXH_aligned);
}
#endif 




XXH_PUBLIC_API void XXH32_canonicalFromHash(XXH32_canonical_t* dst, XXH32_hash_t hash)
{
    XXH_STATIC_ASSERT(sizeof(XXH32_canonical_t) == sizeof(XXH32_hash_t));
    if (XXH_CPU_LITTLE_ENDIAN) hash = XXH_swap32(hash);
    XXH_memcpy(dst, &hash, sizeof(*dst));
}

XXH_PUBLIC_API XXH32_hash_t XXH32_hashFromCanonical(const XXH32_canonical_t* src)
{
    return XXH_readBE32(src);
}


#ifndef XXH_NO_LONG_LONG





typedef XXH64_hash_t xxh_u64;

#ifdef XXH_OLD_NAMES
#  define U64 xxh_u64
#endif

#if (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==3))

#elif (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==2))


static xxh_u64 XXH_read64(const void* memPtr)
{
    return *(const xxh_u64*) memPtr;
}

#elif (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==1))


#ifdef XXH_OLD_NAMES
typedef union { xxh_u32 u32; xxh_u64 u64; } __attribute__((packed)) unalign64;
#endif
static xxh_u64 XXH_read64(const void* ptr)
{
    typedef __attribute__((aligned(1))) xxh_u64 xxh_unalign64;
    return *((const xxh_unalign64*)ptr);
}

#else


static xxh_u64 XXH_read64(const void* memPtr)
{
    xxh_u64 val;
    XXH_memcpy(&val, memPtr, sizeof(val));
    return val;
}

#endif   

#if defined(_MSC_VER)     
#  define XXH_swap64 _byteswap_uint64
#elif XXH_GCC_VERSION >= 403
#  define XXH_swap64 __builtin_bswap64
#else
static xxh_u64 XXH_swap64(xxh_u64 x)
{
    return  ((x << 56) & 0xff00000000000000ULL) |
            ((x << 40) & 0x00ff000000000000ULL) |
            ((x << 24) & 0x0000ff0000000000ULL) |
            ((x << 8)  & 0x000000ff00000000ULL) |
            ((x >> 8)  & 0x00000000ff000000ULL) |
            ((x >> 24) & 0x0000000000ff0000ULL) |
            ((x >> 40) & 0x000000000000ff00ULL) |
            ((x >> 56) & 0x00000000000000ffULL);
}
#endif



#if (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==3))

XXH_FORCE_INLINE xxh_u64 XXH_readLE64(const void* memPtr)
{
    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
    return bytePtr[0]
         | ((xxh_u64)bytePtr[1] << 8)
         | ((xxh_u64)bytePtr[2] << 16)
         | ((xxh_u64)bytePtr[3] << 24)
         | ((xxh_u64)bytePtr[4] << 32)
         | ((xxh_u64)bytePtr[5] << 40)
         | ((xxh_u64)bytePtr[6] << 48)
         | ((xxh_u64)bytePtr[7] << 56);
}

XXH_FORCE_INLINE xxh_u64 XXH_readBE64(const void* memPtr)
{
    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
    return bytePtr[7]
         | ((xxh_u64)bytePtr[6] << 8)
         | ((xxh_u64)bytePtr[5] << 16)
         | ((xxh_u64)bytePtr[4] << 24)
         | ((xxh_u64)bytePtr[3] << 32)
         | ((xxh_u64)bytePtr[2] << 40)
         | ((xxh_u64)bytePtr[1] << 48)
         | ((xxh_u64)bytePtr[0] << 56);
}

#else
XXH_FORCE_INLINE xxh_u64 XXH_readLE64(const void* ptr)
{
    return XXH_CPU_LITTLE_ENDIAN ? XXH_read64(ptr) : XXH_swap64(XXH_read64(ptr));
}

static xxh_u64 XXH_readBE64(const void* ptr)
{
    return XXH_CPU_LITTLE_ENDIAN ? XXH_swap64(XXH_read64(ptr)) : XXH_read64(ptr);
}
#endif

XXH_FORCE_INLINE xxh_u64
XXH_readLE64_align(const void* ptr, XXH_alignment align)
{
    if (align==XXH_unaligned)
        return XXH_readLE64(ptr);
    else
        return XXH_CPU_LITTLE_ENDIAN ? *(const xxh_u64*)ptr : XXH_swap64(*(const xxh_u64*)ptr);
}





#define XXH_PRIME64_1  0x9E3779B185EBCA87ULL  
#define XXH_PRIME64_2  0xC2B2AE3D27D4EB4FULL  
#define XXH_PRIME64_3  0x165667B19E3779F9ULL  
#define XXH_PRIME64_4  0x85EBCA77C2B2AE63ULL  
#define XXH_PRIME64_5  0x27D4EB2F165667C5ULL  

#ifdef XXH_OLD_NAMES
#  define PRIME64_1 XXH_PRIME64_1
#  define PRIME64_2 XXH_PRIME64_2
#  define PRIME64_3 XXH_PRIME64_3
#  define PRIME64_4 XXH_PRIME64_4
#  define PRIME64_5 XXH_PRIME64_5
#endif


static xxh_u64 XXH64_round(xxh_u64 acc, xxh_u64 input)
{
    acc += input * XXH_PRIME64_2;
    acc  = XXH_rotl64(acc, 31);
    acc *= XXH_PRIME64_1;
    return acc;
}

static xxh_u64 XXH64_mergeRound(xxh_u64 acc, xxh_u64 val)
{
    val  = XXH64_round(0, val);
    acc ^= val;
    acc  = acc * XXH_PRIME64_1 + XXH_PRIME64_4;
    return acc;
}


static xxh_u64 XXH64_avalanche(xxh_u64 hash)
{
    hash ^= hash >> 33;
    hash *= XXH_PRIME64_2;
    hash ^= hash >> 29;
    hash *= XXH_PRIME64_3;
    hash ^= hash >> 32;
    return hash;
}


#define XXH_get64bits(p) XXH_readLE64_align(p, align)


static XXH_PUREF xxh_u64
XXH64_finalize(xxh_u64 hash, const xxh_u8* ptr, size_t len, XXH_alignment align)
{
    if (ptr==NULL) XXH_ASSERT(len == 0);
    len &= 31;
    while (len >= 8) {
        xxh_u64 const k1 = XXH64_round(0, XXH_get64bits(ptr));
        ptr += 8;
        hash ^= k1;
        hash  = XXH_rotl64(hash,27) * XXH_PRIME64_1 + XXH_PRIME64_4;
        len -= 8;
    }
    if (len >= 4) {
        hash ^= (xxh_u64)(XXH_get32bits(ptr)) * XXH_PRIME64_1;
        ptr += 4;
        hash = XXH_rotl64(hash, 23) * XXH_PRIME64_2 + XXH_PRIME64_3;
        len -= 4;
    }
    while (len > 0) {
        hash ^= (*ptr++) * XXH_PRIME64_5;
        hash = XXH_rotl64(hash, 11) * XXH_PRIME64_1;
        --len;
    }
    return  XXH64_avalanche(hash);
}

#ifdef XXH_OLD_NAMES
#  define PROCESS1_64 XXH_PROCESS1_64
#  define PROCESS4_64 XXH_PROCESS4_64
#  define PROCESS8_64 XXH_PROCESS8_64
#else
#  undef XXH_PROCESS1_64
#  undef XXH_PROCESS4_64
#  undef XXH_PROCESS8_64
#endif


XXH_FORCE_INLINE XXH_PUREF xxh_u64
XXH64_endian_align(const xxh_u8* input, size_t len, xxh_u64 seed, XXH_alignment align)
{
    xxh_u64 h64;
    if (input==NULL) XXH_ASSERT(len == 0);

    if (len>=32) {
        const xxh_u8* const bEnd = input + len;
        const xxh_u8* const limit = bEnd - 31;
        xxh_u64 v1 = seed + XXH_PRIME64_1 + XXH_PRIME64_2;
        xxh_u64 v2 = seed + XXH_PRIME64_2;
        xxh_u64 v3 = seed + 0;
        xxh_u64 v4 = seed - XXH_PRIME64_1;

        do {
            v1 = XXH64_round(v1, XXH_get64bits(input)); input+=8;
            v2 = XXH64_round(v2, XXH_get64bits(input)); input+=8;
            v3 = XXH64_round(v3, XXH_get64bits(input)); input+=8;
            v4 = XXH64_round(v4, XXH_get64bits(input)); input+=8;
        } while (input<limit);

        h64 = XXH_rotl64(v1, 1) + XXH_rotl64(v2, 7) + XXH_rotl64(v3, 12) + XXH_rotl64(v4, 18);
        h64 = XXH64_mergeRound(h64, v1);
        h64 = XXH64_mergeRound(h64, v2);
        h64 = XXH64_mergeRound(h64, v3);
        h64 = XXH64_mergeRound(h64, v4);

    } else {
        h64  = seed + XXH_PRIME64_5;
    }

    h64 += (xxh_u64) len;

    return XXH64_finalize(h64, input, len, align);
}



XXH_PUBLIC_API XXH64_hash_t XXH64 (const void* input, size_t len, XXH64_hash_t seed)
{
#if !defined(XXH_NO_STREAM) && XXH_SIZE_OPT >= 2
    
    XXH64_state_t state;
    XXH64_reset(&state, seed);
    XXH64_update(&state, (const xxh_u8*)input, len);
    return XXH64_digest(&state);
#else
    if (XXH_FORCE_ALIGN_CHECK) {
        if ((((size_t)input) & 7)==0) {  
            return XXH64_endian_align((const xxh_u8*)input, len, seed, XXH_aligned);
    }   }

    return XXH64_endian_align((const xxh_u8*)input, len, seed, XXH_unaligned);

#endif
}


#ifndef XXH_NO_STREAM

XXH_PUBLIC_API XXH64_state_t* XXH64_createState(void)
{
    return (XXH64_state_t*)XXH_malloc(sizeof(XXH64_state_t));
}

XXH_PUBLIC_API XXH_errorcode XXH64_freeState(XXH64_state_t* statePtr)
{
    XXH_free(statePtr);
    return XXH_OK;
}


XXH_PUBLIC_API void XXH64_copyState(XXH64_state_t* dstState, const XXH64_state_t* srcState)
{
    XXH_memcpy(dstState, srcState, sizeof(*dstState));
}


XXH_PUBLIC_API XXH_errorcode XXH64_reset(XXH64_state_t* statePtr, XXH64_hash_t seed)
{
    XXH_ASSERT(statePtr != NULL);
    memset(statePtr, 0, sizeof(*statePtr));
    statePtr->v[0] = seed + XXH_PRIME64_1 + XXH_PRIME64_2;
    statePtr->v[1] = seed + XXH_PRIME64_2;
    statePtr->v[2] = seed + 0;
    statePtr->v[3] = seed - XXH_PRIME64_1;
    return XXH_OK;
}


XXH_PUBLIC_API XXH_errorcode
XXH64_update (XXH64_state_t* state, const void* input, size_t len)
{
    if (input==NULL) {
        XXH_ASSERT(len == 0);
        return XXH_OK;
    }

    {   const xxh_u8* p = (const xxh_u8*)input;
        const xxh_u8* const bEnd = p + len;

        state->total_len += len;

        if (state->memsize + len < 32) {  
            XXH_memcpy(((xxh_u8*)state->mem64) + state->memsize, input, len);
            state->memsize += (xxh_u32)len;
            return XXH_OK;
        }

        if (state->memsize) {   
            XXH_memcpy(((xxh_u8*)state->mem64) + state->memsize, input, 32-state->memsize);
            state->v[0] = XXH64_round(state->v[0], XXH_readLE64(state->mem64+0));
            state->v[1] = XXH64_round(state->v[1], XXH_readLE64(state->mem64+1));
            state->v[2] = XXH64_round(state->v[2], XXH_readLE64(state->mem64+2));
            state->v[3] = XXH64_round(state->v[3], XXH_readLE64(state->mem64+3));
            p += 32 - state->memsize;
            state->memsize = 0;
        }

        if (p+32 <= bEnd) {
            const xxh_u8* const limit = bEnd - 32;

            do {
                state->v[0] = XXH64_round(state->v[0], XXH_readLE64(p)); p+=8;
                state->v[1] = XXH64_round(state->v[1], XXH_readLE64(p)); p+=8;
                state->v[2] = XXH64_round(state->v[2], XXH_readLE64(p)); p+=8;
                state->v[3] = XXH64_round(state->v[3], XXH_readLE64(p)); p+=8;
            } while (p<=limit);

        }

        if (p < bEnd) {
            XXH_memcpy(state->mem64, p, (size_t)(bEnd-p));
            state->memsize = (unsigned)(bEnd-p);
        }
    }

    return XXH_OK;
}



XXH_PUBLIC_API XXH64_hash_t XXH64_digest(const XXH64_state_t* state)
{
    xxh_u64 h64;

    if (state->total_len >= 32) {
        h64 = XXH_rotl64(state->v[0], 1) + XXH_rotl64(state->v[1], 7) + XXH_rotl64(state->v[2], 12) + XXH_rotl64(state->v[3], 18);
        h64 = XXH64_mergeRound(h64, state->v[0]);
        h64 = XXH64_mergeRound(h64, state->v[1]);
        h64 = XXH64_mergeRound(h64, state->v[2]);
        h64 = XXH64_mergeRound(h64, state->v[3]);
    } else {
        h64  = state->v[2]  + XXH_PRIME64_5;
    }

    h64 += (xxh_u64) state->total_len;

    return XXH64_finalize(h64, (const xxh_u8*)state->mem64, (size_t)state->total_len, XXH_aligned);
}
#endif 




XXH_PUBLIC_API void XXH64_canonicalFromHash(XXH64_canonical_t* dst, XXH64_hash_t hash)
{
    XXH_STATIC_ASSERT(sizeof(XXH64_canonical_t) == sizeof(XXH64_hash_t));
    if (XXH_CPU_LITTLE_ENDIAN) hash = XXH_swap64(hash);
    XXH_memcpy(dst, &hash, sizeof(*dst));
}


XXH_PUBLIC_API XXH64_hash_t XXH64_hashFromCanonical(const XXH64_canonical_t* src)
{
    return XXH_readBE64(src);
}

#ifndef XXH_NO_XXH3






#if ((defined(sun) || defined(__sun)) && __cplusplus) 
#  define XXH_RESTRICT 
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L   
#  define XXH_RESTRICT   restrict
#else

#  define XXH_RESTRICT   
#endif

#if (defined(__GNUC__) && (__GNUC__ >= 3))  \
  || (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 800)) \
  || defined(__clang__)
#    define XXH_likely(x) __builtin_expect(x, 1)
#    define XXH_unlikely(x) __builtin_expect(x, 0)
#else
#    define XXH_likely(x) (x)
#    define XXH_unlikely(x) (x)
#endif

#if defined(__GNUC__) || defined(__clang__)
#  if defined(__ARM_FEATURE_SVE)
#    include <arm_sve.h>
#  elif defined(__ARM_NEON__) || defined(__ARM_NEON) \
   || defined(__aarch64__)  || defined(_M_ARM) \
   || defined(_M_ARM64)     || defined(_M_ARM64EC)
#    define inline __inline__  
#    include <arm_neon.h>
#    undef inline
#  elif defined(__AVX2__)
#    include <immintrin.h>
#  elif defined(__SSE2__)
#    include <emmintrin.h>
#  endif
#endif

#if defined(_MSC_VER)
#  include <intrin.h>
#endif


#if defined(__thumb__) && !defined(__thumb2__) && defined(__ARM_ARCH_ISA_ARM)
#   warning "XXH3 is highly inefficient without ARM or Thumb-2."
#endif



#ifdef XXH_DOXYGEN

#  define XXH_VECTOR XXH_SCALAR

enum XXH_VECTOR_TYPE  {
    XXH_SCALAR = 0,  
    XXH_SSE2   = 1,  
    XXH_AVX2   = 2,  
    XXH_AVX512 = 3,  
    XXH_NEON   = 4,  
    XXH_VSX    = 5,  
    XXH_SVE    = 6,  
};

#  define XXH_ACC_ALIGN 8
#endif


#ifndef XXH_DOXYGEN
#  define XXH_SCALAR 0
#  define XXH_SSE2   1
#  define XXH_AVX2   2
#  define XXH_AVX512 3
#  define XXH_NEON   4
#  define XXH_VSX    5
#  define XXH_SVE    6
#endif

#ifndef XXH_VECTOR    
#  if defined(__ARM_FEATURE_SVE)
#    define XXH_VECTOR XXH_SVE
#  elif ( \
        defined(__ARM_NEON__) || defined(__ARM_NEON)  \
     || defined(_M_ARM) || defined(_M_ARM64) || defined(_M_ARM64EC)  \
   ) && ( \
        defined(_WIN32) || defined(__LITTLE_ENDIAN__)  \
    || (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) \
   )
#    define XXH_VECTOR XXH_NEON
#  elif defined(__AVX512F__)
#    define XXH_VECTOR XXH_AVX512
#  elif defined(__AVX2__)
#    define XXH_VECTOR XXH_AVX2
#  elif defined(__SSE2__) || defined(_M_AMD64) || defined(_M_X64) || (defined(_M_IX86_FP) && (_M_IX86_FP == 2))
#    define XXH_VECTOR XXH_SSE2
#  elif (defined(__PPC64__) && defined(__POWER8_VECTOR__)) \
     || (defined(__s390x__) && defined(__VEC__)) \
     && defined(__GNUC__) 
#    define XXH_VECTOR XXH_VSX
#  else
#    define XXH_VECTOR XXH_SCALAR
#  endif
#endif


#if (XXH_VECTOR == XXH_SVE) && !defined(__ARM_FEATURE_SVE)
#  ifdef _MSC_VER
#    pragma warning(once : 4606)
#  else
#    warning "__ARM_FEATURE_SVE isn't supported. Use SCALAR instead."
#  endif
#  undef XXH_VECTOR
#  define XXH_VECTOR XXH_SCALAR
#endif


#ifndef XXH_ACC_ALIGN
#  if defined(XXH_X86DISPATCH)
#     define XXH_ACC_ALIGN 64  
#  elif XXH_VECTOR == XXH_SCALAR  
#     define XXH_ACC_ALIGN 8
#  elif XXH_VECTOR == XXH_SSE2  
#     define XXH_ACC_ALIGN 16
#  elif XXH_VECTOR == XXH_AVX2  
#     define XXH_ACC_ALIGN 32
#  elif XXH_VECTOR == XXH_NEON  
#     define XXH_ACC_ALIGN 16
#  elif XXH_VECTOR == XXH_VSX   
#     define XXH_ACC_ALIGN 16
#  elif XXH_VECTOR == XXH_AVX512  
#     define XXH_ACC_ALIGN 64
#  elif XXH_VECTOR == XXH_SVE   
#     define XXH_ACC_ALIGN 64
#  endif
#endif

#if defined(XXH_X86DISPATCH) || XXH_VECTOR == XXH_SSE2 \
    || XXH_VECTOR == XXH_AVX2 || XXH_VECTOR == XXH_AVX512
#  define XXH_SEC_ALIGN XXH_ACC_ALIGN
#elif XXH_VECTOR == XXH_SVE
#  define XXH_SEC_ALIGN XXH_ACC_ALIGN
#else
#  define XXH_SEC_ALIGN 8
#endif


#if XXH_VECTOR == XXH_AVX2  \
  && defined(__GNUC__) && !defined(__clang__)  \
  && defined(__OPTIMIZE__) && XXH_SIZE_OPT <= 0 
#  pragma GCC push_options
#  pragma GCC optimize("-O2")
#endif


#if XXH_VECTOR == XXH_NEON



# if !defined(XXH_NO_VZIP_HACK)  \
   && (defined(__GNUC__) || defined(__clang__)) \
   && (defined(__arm__) || defined(__thumb__) || defined(_M_ARM))
#  define XXH_SPLIT_IN_PLACE(in, outLo, outHi)                                              \
    do {                                                                                    \
       \
           \
       \
      __asm__("vzip.32  %e0, %f0" : "+w" (in));                                             \
      (outLo) = vget_low_u32 (vreinterpretq_u32_u64(in));                                   \
      (outHi) = vget_high_u32(vreinterpretq_u32_u64(in));                                   \
   } while (0)
# else
#  define XXH_SPLIT_IN_PLACE(in, outLo, outHi)                                            \
    do {                                                                                  \
      (outLo) = vmovn_u64    (in);                                                        \
      (outHi) = vshrn_n_u64  ((in), 32);                                                  \
    } while (0)
# endif


#if defined(__aarch64__) && defined(__GNUC__) && !defined(__clang__)
XXH_FORCE_INLINE uint64x2_t XXH_vld1q_u64(void const* ptr) 
{
    return *(uint64x2_t const*)ptr;
}
#else
XXH_FORCE_INLINE uint64x2_t XXH_vld1q_u64(void const* ptr)
{
    return vreinterpretq_u64_u8(vld1q_u8((uint8_t const*)ptr));
}
#endif

# ifndef XXH3_NEON_LANES
#  if (defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64) || defined(_M_ARM64EC)) \
   && !defined(__APPLE__) && XXH_SIZE_OPT <= 0
#   define XXH3_NEON_LANES 6
#  else
#   define XXH3_NEON_LANES XXH_ACC_NB
#  endif
# endif
#endif  


#if XXH_VECTOR == XXH_VSX

#  pragma push_macro("bool")
#  pragma push_macro("vector")
#  pragma push_macro("pixel")

#  undef bool
#  undef vector
#  undef pixel

#  if defined(__s390x__)
#    include <s390intrin.h>
#  else
#    include <altivec.h>
#  endif


#  pragma pop_macro("pixel")
#  pragma pop_macro("vector")
#  pragma pop_macro("bool")

typedef __vector unsigned long long xxh_u64x2;
typedef __vector unsigned char xxh_u8x16;
typedef __vector unsigned xxh_u32x4;

# ifndef XXH_VSX_BE
#  if defined(__BIG_ENDIAN__) \
  || (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#    define XXH_VSX_BE 1
#  elif defined(__VEC_ELEMENT_REG_ORDER__) && __VEC_ELEMENT_REG_ORDER__ == __ORDER_BIG_ENDIAN__
#    warning "-maltivec=be is not recommended. Please use native endianness."
#    define XXH_VSX_BE 1
#  else
#    define XXH_VSX_BE 0
#  endif
# endif 

# if XXH_VSX_BE
#  if defined(__POWER9_VECTOR__) || (defined(__clang__) && defined(__s390x__))
#    define XXH_vec_revb vec_revb
#  else

XXH_FORCE_INLINE xxh_u64x2 XXH_vec_revb(xxh_u64x2 val)
{
    xxh_u8x16 const vByteSwap = { 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
                                  0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08 };
    return vec_perm(val, val, vByteSwap);
}
#  endif
# endif 


XXH_FORCE_INLINE xxh_u64x2 XXH_vec_loadu(const void *ptr)
{
    xxh_u64x2 ret;
    XXH_memcpy(&ret, ptr, sizeof(xxh_u64x2));
# if XXH_VSX_BE
    ret = XXH_vec_revb(ret);
# endif
    return ret;
}


# if defined(__s390x__)
 
#  define XXH_vec_mulo vec_mulo
#  define XXH_vec_mule vec_mule
# elif defined(__clang__) && XXH_HAS_BUILTIN(__builtin_altivec_vmuleuw) && !defined(__ibmxl__)

 
#  define XXH_vec_mulo __builtin_altivec_vmulouw
#  define XXH_vec_mule __builtin_altivec_vmuleuw
# else


XXH_FORCE_INLINE xxh_u64x2 XXH_vec_mulo(xxh_u32x4 a, xxh_u32x4 b)
{
    xxh_u64x2 result;
    __asm__("vmulouw %0, %1, %2" : "=v" (result) : "v" (a), "v" (b));
    return result;
}
XXH_FORCE_INLINE xxh_u64x2 XXH_vec_mule(xxh_u32x4 a, xxh_u32x4 b)
{
    xxh_u64x2 result;
    __asm__("vmuleuw %0, %1, %2" : "=v" (result) : "v" (a), "v" (b));
    return result;
}
# endif 
#endif 

#if XXH_VECTOR == XXH_SVE
#define ACCRND(acc, offset) \
do { \
    svuint64_t input_vec = svld1_u64(mask, xinput + offset);         \
    svuint64_t secret_vec = svld1_u64(mask, xsecret + offset);       \
    svuint64_t mixed = sveor_u64_x(mask, secret_vec, input_vec);     \
    svuint64_t swapped = svtbl_u64(input_vec, kSwap);                \
    svuint64_t mixed_lo = svextw_u64_x(mask, mixed);                 \
    svuint64_t mixed_hi = svlsr_n_u64_x(mask, mixed, 32);            \
    svuint64_t mul = svmad_u64_x(mask, mixed_lo, mixed_hi, swapped); \
    acc = svadd_u64_x(mask, acc, mul);                               \
} while (0)
#endif 



#if defined(XXH_NO_PREFETCH)
#  define XXH_PREFETCH(ptr)  (void)(ptr)  
#else
#  if XXH_SIZE_OPT >= 1
#    define XXH_PREFETCH(ptr) (void)(ptr)
#  elif defined(_MSC_VER) && (defined(_M_X64) || defined(_M_IX86))  
#    include <mmintrin.h>   
#    define XXH_PREFETCH(ptr)  _mm_prefetch((const char*)(ptr), _MM_HINT_T0)
#  elif defined(__GNUC__) && ( (__GNUC__ >= 4) || ( (__GNUC__ == 3) && (__GNUC_MINOR__ >= 1) ) )
#    define XXH_PREFETCH(ptr)  __builtin_prefetch((ptr), 0 , 3 )
#  else
#    define XXH_PREFETCH(ptr) (void)(ptr)  
#  endif
#endif  




#define XXH_SECRET_DEFAULT_SIZE 192   

#if (XXH_SECRET_DEFAULT_SIZE < XXH3_SECRET_SIZE_MIN)
#  error "default keyset is not large enough"
#endif


XXH_ALIGN(64) static const xxh_u8 XXH3_kSecret[XXH_SECRET_DEFAULT_SIZE] = {
    0xb8, 0xfe, 0x6c, 0x39, 0x23, 0xa4, 0x4b, 0xbe, 0x7c, 0x01, 0x81, 0x2c, 0xf7, 0x21, 0xad, 0x1c,
    0xde, 0xd4, 0x6d, 0xe9, 0x83, 0x90, 0x97, 0xdb, 0x72, 0x40, 0xa4, 0xa4, 0xb7, 0xb3, 0x67, 0x1f,
    0xcb, 0x79, 0xe6, 0x4e, 0xcc, 0xc0, 0xe5, 0x78, 0x82, 0x5a, 0xd0, 0x7d, 0xcc, 0xff, 0x72, 0x21,
    0xb8, 0x08, 0x46, 0x74, 0xf7, 0x43, 0x24, 0x8e, 0xe0, 0x35, 0x90, 0xe6, 0x81, 0x3a, 0x26, 0x4c,
    0x3c, 0x28, 0x52, 0xbb, 0x91, 0xc3, 0x00, 0xcb, 0x88, 0xd0, 0x65, 0x8b, 0x1b, 0x53, 0x2e, 0xa3,
    0x71, 0x64, 0x48, 0x97, 0xa2, 0x0d, 0xf9, 0x4e, 0x38, 0x19, 0xef, 0x46, 0xa9, 0xde, 0xac, 0xd8,
    0xa8, 0xfa, 0x76, 0x3f, 0xe3, 0x9c, 0x34, 0x3f, 0xf9, 0xdc, 0xbb, 0xc7, 0xc7, 0x0b, 0x4f, 0x1d,
    0x8a, 0x51, 0xe0, 0x4b, 0xcd, 0xb4, 0x59, 0x31, 0xc8, 0x9f, 0x7e, 0xc9, 0xd9, 0x78, 0x73, 0x64,
    0xea, 0xc5, 0xac, 0x83, 0x34, 0xd3, 0xeb, 0xc3, 0xc5, 0x81, 0xa0, 0xff, 0xfa, 0x13, 0x63, 0xeb,
    0x17, 0x0d, 0xdd, 0x51, 0xb7, 0xf0, 0xda, 0x49, 0xd3, 0x16, 0x55, 0x26, 0x29, 0xd4, 0x68, 0x9e,
    0x2b, 0x16, 0xbe, 0x58, 0x7d, 0x47, 0xa1, 0xfc, 0x8f, 0xf8, 0xb8, 0xd1, 0x7a, 0xd0, 0x31, 0xce,
    0x45, 0xcb, 0x3a, 0x8f, 0x95, 0x16, 0x04, 0x28, 0xaf, 0xd7, 0xfb, 0xca, 0xbb, 0x4b, 0x40, 0x7e,
};


#ifdef XXH_OLD_NAMES
#  define kSecret XXH3_kSecret
#endif

#ifdef XXH_DOXYGEN

XXH_FORCE_INLINE xxh_u64
XXH_mult32to64(xxh_u64 x, xxh_u64 y)
{
   return (x & 0xFFFFFFFF) * (y & 0xFFFFFFFF);
}
#elif defined(_MSC_VER) && defined(_M_IX86)
#    define XXH_mult32to64(x, y) __emulu((unsigned)(x), (unsigned)(y))
#else

#    define XXH_mult32to64(x, y) ((xxh_u64)(xxh_u32)(x) * (xxh_u64)(xxh_u32)(y))
#endif


static XXH128_hash_t
XXH_mult64to128(xxh_u64 lhs, xxh_u64 rhs)
{
    
#if (defined(__GNUC__) || defined(__clang__)) && !defined(__wasm__) \
    && defined(__SIZEOF_INT128__) \
    || (defined(_INTEGRAL_MAX_BITS) && _INTEGRAL_MAX_BITS >= 128)

    __uint128_t const product = (__uint128_t)lhs * (__uint128_t)rhs;
    XXH128_hash_t r128;
    r128.low64  = (xxh_u64)(product);
    r128.high64 = (xxh_u64)(product >> 64);
    return r128;

    
#elif (defined(_M_X64) || defined(_M_IA64)) && !defined(_M_ARM64EC)

#ifndef _MSC_VER
#   pragma intrinsic(_umul128)
#endif
    xxh_u64 product_high;
    xxh_u64 const product_low = _umul128(lhs, rhs, &product_high);
    XXH128_hash_t r128;
    r128.low64  = product_low;
    r128.high64 = product_high;
    return r128;

    
#elif defined(_M_ARM64) || defined(_M_ARM64EC)

#ifndef _MSC_VER
#   pragma intrinsic(__umulh)
#endif
    XXH128_hash_t r128;
    r128.low64  = lhs * rhs;
    r128.high64 = __umulh(lhs, rhs);
    return r128;

#else
    

    
    xxh_u64 const lo_lo = XXH_mult32to64(lhs & 0xFFFFFFFF, rhs & 0xFFFFFFFF);
    xxh_u64 const hi_lo = XXH_mult32to64(lhs >> 32,        rhs & 0xFFFFFFFF);
    xxh_u64 const lo_hi = XXH_mult32to64(lhs & 0xFFFFFFFF, rhs >> 32);
    xxh_u64 const hi_hi = XXH_mult32to64(lhs >> 32,        rhs >> 32);

    
    xxh_u64 const cross = (lo_lo >> 32) + (hi_lo & 0xFFFFFFFF) + lo_hi;
    xxh_u64 const upper = (hi_lo >> 32) + (cross >> 32)        + hi_hi;
    xxh_u64 const lower = (cross << 32) | (lo_lo & 0xFFFFFFFF);

    XXH128_hash_t r128;
    r128.low64  = lower;
    r128.high64 = upper;
    return r128;
#endif
}


static xxh_u64
XXH3_mul128_fold64(xxh_u64 lhs, xxh_u64 rhs)
{
    XXH128_hash_t product = XXH_mult64to128(lhs, rhs);
    return product.low64 ^ product.high64;
}


XXH_FORCE_INLINE XXH_CONSTF xxh_u64 XXH_xorshift64(xxh_u64 v64, int shift)
{
    XXH_ASSERT(0 <= shift && shift < 64);
    return v64 ^ (v64 >> shift);
}


static XXH64_hash_t XXH3_avalanche(xxh_u64 h64)
{
    h64 = XXH_xorshift64(h64, 37);
    h64 *= 0x165667919E3779F9ULL;
    h64 = XXH_xorshift64(h64, 32);
    return h64;
}


static XXH64_hash_t XXH3_rrmxmx(xxh_u64 h64, xxh_u64 len)
{
    
    h64 ^= XXH_rotl64(h64, 49) ^ XXH_rotl64(h64, 24);
    h64 *= 0x9FB21C651E98DF25ULL;
    h64 ^= (h64 >> 35) + len ;
    h64 *= 0x9FB21C651E98DF25ULL;
    return XXH_xorshift64(h64, 28);
}





XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
XXH3_len_1to3_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    XXH_ASSERT(input != NULL);
    XXH_ASSERT(1 <= len && len <= 3);
    XXH_ASSERT(secret != NULL);
    
    {   xxh_u8  const c1 = input[0];
        xxh_u8  const c2 = input[len >> 1];
        xxh_u8  const c3 = input[len - 1];
        xxh_u32 const combined = ((xxh_u32)c1 << 16) | ((xxh_u32)c2  << 24)
                               | ((xxh_u32)c3 <<  0) | ((xxh_u32)len << 8);
        xxh_u64 const bitflip = (XXH_readLE32(secret) ^ XXH_readLE32(secret+4)) + seed;
        xxh_u64 const keyed = (xxh_u64)combined ^ bitflip;
        return XXH64_avalanche(keyed);
    }
}

XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
XXH3_len_4to8_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    XXH_ASSERT(input != NULL);
    XXH_ASSERT(secret != NULL);
    XXH_ASSERT(4 <= len && len <= 8);
    seed ^= (xxh_u64)XXH_swap32((xxh_u32)seed) << 32;
    {   xxh_u32 const input1 = XXH_readLE32(input);
        xxh_u32 const input2 = XXH_readLE32(input + len - 4);
        xxh_u64 const bitflip = (XXH_readLE64(secret+8) ^ XXH_readLE64(secret+16)) - seed;
        xxh_u64 const input64 = input2 + (((xxh_u64)input1) << 32);
        xxh_u64 const keyed = input64 ^ bitflip;
        return XXH3_rrmxmx(keyed, len);
    }
}

XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
XXH3_len_9to16_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    XXH_ASSERT(input != NULL);
    XXH_ASSERT(secret != NULL);
    XXH_ASSERT(9 <= len && len <= 16);
    {   xxh_u64 const bitflip1 = (XXH_readLE64(secret+24) ^ XXH_readLE64(secret+32)) + seed;
        xxh_u64 const bitflip2 = (XXH_readLE64(secret+40) ^ XXH_readLE64(secret+48)) - seed;
        xxh_u64 const input_lo = XXH_readLE64(input)           ^ bitflip1;
        xxh_u64 const input_hi = XXH_readLE64(input + len - 8) ^ bitflip2;
        xxh_u64 const acc = len
                          + XXH_swap64(input_lo) + input_hi
                          + XXH3_mul128_fold64(input_lo, input_hi);
        return XXH3_avalanche(acc);
    }
}

XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
XXH3_len_0to16_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    XXH_ASSERT(len <= 16);
    {   if (XXH_likely(len >  8)) return XXH3_len_9to16_64b(input, len, secret, seed);
        if (XXH_likely(len >= 4)) return XXH3_len_4to8_64b(input, len, secret, seed);
        if (len) return XXH3_len_1to3_64b(input, len, secret, seed);
        return XXH64_avalanche(seed ^ (XXH_readLE64(secret+56) ^ XXH_readLE64(secret+64)));
    }
}


XXH_FORCE_INLINE xxh_u64 XXH3_mix16B(const xxh_u8* XXH_RESTRICT input,
                                     const xxh_u8* XXH_RESTRICT secret, xxh_u64 seed64)
{
#if defined(__GNUC__) && !defined(__clang__)  \
  && defined(__i386__) && defined(__SSE2__)   \
  && !defined(XXH_ENABLE_AUTOVECTORIZE)      
    
    XXH_COMPILER_GUARD(seed64);
#endif
    {   xxh_u64 const input_lo = XXH_readLE64(input);
        xxh_u64 const input_hi = XXH_readLE64(input+8);
        return XXH3_mul128_fold64(
            input_lo ^ (XXH_readLE64(secret)   + seed64),
            input_hi ^ (XXH_readLE64(secret+8) - seed64)
        );
    }
}


XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
XXH3_len_17to128_64b(const xxh_u8* XXH_RESTRICT input, size_t len,
                     const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
                     XXH64_hash_t seed)
{
    XXH_ASSERT(secretSize >= XXH3_SECRET_SIZE_MIN); (void)secretSize;
    XXH_ASSERT(16 < len && len <= 128);

    {   xxh_u64 acc = len * XXH_PRIME64_1;
#if XXH_SIZE_OPT >= 1
        
        size_t i = (len - 1) / 32;
        do {
            acc += XXH3_mix16B(input+16 * i, secret+32*i, seed);
            acc += XXH3_mix16B(input+len-16*(i+1), secret+32*i+16, seed);
        } while (i-- != 0);
#else
        if (len > 32) {
            if (len > 64) {
                if (len > 96) {
                    acc += XXH3_mix16B(input+48, secret+96, seed);
                    acc += XXH3_mix16B(input+len-64, secret+112, seed);
                }
                acc += XXH3_mix16B(input+32, secret+64, seed);
                acc += XXH3_mix16B(input+len-48, secret+80, seed);
            }
            acc += XXH3_mix16B(input+16, secret+32, seed);
            acc += XXH3_mix16B(input+len-32, secret+48, seed);
        }
        acc += XXH3_mix16B(input+0, secret+0, seed);
        acc += XXH3_mix16B(input+len-16, secret+16, seed);
#endif
        return XXH3_avalanche(acc);
    }
}

#define XXH3_MIDSIZE_MAX 240

XXH_NO_INLINE XXH_PUREF XXH64_hash_t
XXH3_len_129to240_64b(const xxh_u8* XXH_RESTRICT input, size_t len,
                      const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
                      XXH64_hash_t seed)
{
    XXH_ASSERT(secretSize >= XXH3_SECRET_SIZE_MIN); (void)secretSize;
    XXH_ASSERT(128 < len && len <= XXH3_MIDSIZE_MAX);

#define XXH3_MIDSIZE_STARTOFFSET 3
#define XXH3_MIDSIZE_LASTOFFSET  17

    {   xxh_u64 acc = len * XXH_PRIME64_1;
        int const nbRounds = (int)len / 16;
        int i;
        for (i=0; i<8; i++) {
            acc += XXH3_mix16B(input+(16*i), secret+(16*i), seed);
        }
        acc = XXH3_avalanche(acc);
        XXH_ASSERT(nbRounds >= 8);
#if defined(__clang__)                                 \
    && (defined(__ARM_NEON) || defined(__ARM_NEON__))  \
    && !defined(XXH_ENABLE_AUTOVECTORIZE)

#pragma clang loop vectorize(disable)
#endif
        for (i=8 ; i < nbRounds; i++) {
            acc += XXH3_mix16B(input+(16*i), secret+(16*(i-8)) + XXH3_MIDSIZE_STARTOFFSET, seed);
        }

        acc += XXH3_mix16B(input + len - 16, secret + XXH3_SECRET_SIZE_MIN - XXH3_MIDSIZE_LASTOFFSET, seed);
        return XXH3_avalanche(acc);
    }
}




#define XXH_STRIPE_LEN 64
#define XXH_SECRET_CONSUME_RATE 8
#define XXH_ACC_NB (XXH_STRIPE_LEN / sizeof(xxh_u64))

#ifdef XXH_OLD_NAMES
#  define STRIPE_LEN XXH_STRIPE_LEN
#  define ACC_NB XXH_ACC_NB
#endif

#ifndef XXH_PREFETCH_DIST
#  ifdef __clang__
#    define XXH_PREFETCH_DIST 320
#  else
#    if (XXH_VECTOR == XXH_AVX512)
#      define XXH_PREFETCH_DIST 512
#    else
#      define XXH_PREFETCH_DIST 384
#    endif
#  endif
#endif


#define XXH3_ACCUMULATE_TEMPLATE(name)                      \
void                                                        \
XXH3_accumulate_##name(xxh_u64* XXH_RESTRICT acc,           \
                       const xxh_u8* XXH_RESTRICT input,    \
                       const xxh_u8* XXH_RESTRICT secret,   \
                       size_t nbStripes)                    \
{                                                           \
    size_t n;                                               \
    for (n = 0; n < nbStripes; n++ ) {                      \
        const xxh_u8* const in = input + n*XXH_STRIPE_LEN;  \
        XXH_PREFETCH(in + XXH_PREFETCH_DIST);               \
        XXH3_accumulate_512_##name(                         \
                 acc,                                       \
                 in,                                        \
                 secret + n*XXH_SECRET_CONSUME_RATE);       \
    }                                                       \
}


XXH_FORCE_INLINE void XXH_writeLE64(void* dst, xxh_u64 v64)
{
    if (!XXH_CPU_LITTLE_ENDIAN) v64 = XXH_swap64(v64);
    XXH_memcpy(dst, &v64, sizeof(v64));
}


#if !defined (__VMS) \
  && (defined (__cplusplus) \
  || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) ) )
    typedef int64_t xxh_i64;
#else

    typedef long long xxh_i64;
#endif




#if (XXH_VECTOR == XXH_AVX512) \
     || (defined(XXH_DISPATCH_AVX512) && XXH_DISPATCH_AVX512 != 0)

#ifndef XXH_TARGET_AVX512
# define XXH_TARGET_AVX512
#endif

XXH_FORCE_INLINE XXH_TARGET_AVX512 void
XXH3_accumulate_512_avx512(void* XXH_RESTRICT acc,
                     const void* XXH_RESTRICT input,
                     const void* XXH_RESTRICT secret)
{
    __m512i* const xacc = (__m512i *) acc;
    XXH_ASSERT((((size_t)acc) & 63) == 0);
    XXH_STATIC_ASSERT(XXH_STRIPE_LEN == sizeof(__m512i));

    {

        __m512i const data_vec    = _mm512_loadu_si512   (input);

        __m512i const key_vec     = _mm512_loadu_si512   (secret);

        __m512i const data_key    = _mm512_xor_si512     (data_vec, key_vec);

        __m512i const data_key_lo = _mm512_shuffle_epi32 (data_key, (_MM_PERM_ENUM)_MM_SHUFFLE(0, 3, 0, 1));

        __m512i const product     = _mm512_mul_epu32     (data_key, data_key_lo);

        __m512i const data_swap = _mm512_shuffle_epi32(data_vec, (_MM_PERM_ENUM)_MM_SHUFFLE(1, 0, 3, 2));
        __m512i const sum       = _mm512_add_epi64(*xacc, data_swap);

        *xacc = _mm512_add_epi64(product, sum);
    }
}
XXH_FORCE_INLINE XXH_TARGET_AVX512 XXH3_ACCUMULATE_TEMPLATE(avx512)



XXH_FORCE_INLINE XXH_TARGET_AVX512 void
XXH3_scrambleAcc_avx512(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
{
    XXH_ASSERT((((size_t)acc) & 63) == 0);
    XXH_STATIC_ASSERT(XXH_STRIPE_LEN == sizeof(__m512i));
    {   __m512i* const xacc = (__m512i*) acc;
        const __m512i prime32 = _mm512_set1_epi32((int)XXH_PRIME32_1);


        __m512i const acc_vec     = *xacc;
        __m512i const shifted     = _mm512_srli_epi64    (acc_vec, 47);
        __m512i const data_vec    = _mm512_xor_si512     (acc_vec, shifted);

        __m512i const key_vec     = _mm512_loadu_si512   (secret);
        __m512i const data_key    = _mm512_xor_si512     (data_vec, key_vec);


        __m512i const data_key_hi = _mm512_shuffle_epi32 (data_key, (_MM_PERM_ENUM)_MM_SHUFFLE(0, 3, 0, 1));
        __m512i const prod_lo     = _mm512_mul_epu32     (data_key, prime32);
        __m512i const prod_hi     = _mm512_mul_epu32     (data_key_hi, prime32);
        *xacc = _mm512_add_epi64(prod_lo, _mm512_slli_epi64(prod_hi, 32));
    }
}

XXH_FORCE_INLINE XXH_TARGET_AVX512 void
XXH3_initCustomSecret_avx512(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
{
    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE & 63) == 0);
    XXH_STATIC_ASSERT(XXH_SEC_ALIGN == 64);
    XXH_ASSERT(((size_t)customSecret & 63) == 0);
    (void)(&XXH_writeLE64);
    {   int const nbRounds = XXH_SECRET_DEFAULT_SIZE / sizeof(__m512i);
        __m512i const seed_pos = _mm512_set1_epi64(seed64);
        __m512i const seed     = _mm512_mask_sub_epi64(seed_pos, 0xAA, _mm512_set1_epi8(0), seed_pos);

        const __m512i* const src  = (const __m512i*) ((const void*) XXH3_kSecret);
              __m512i* const dest = (      __m512i*) customSecret;
        int i;
        XXH_ASSERT(((size_t)src & 63) == 0);
        XXH_ASSERT(((size_t)dest & 63) == 0);
        for (i=0; i < nbRounds; ++i) {
            dest[i] = _mm512_add_epi64(_mm512_load_si512(src + i), seed);
    }   }
}

#endif

#if (XXH_VECTOR == XXH_AVX2) \
    || (defined(XXH_DISPATCH_AVX2) && XXH_DISPATCH_AVX2 != 0)

#ifndef XXH_TARGET_AVX2
# define XXH_TARGET_AVX2
#endif

XXH_FORCE_INLINE XXH_TARGET_AVX2 void
XXH3_accumulate_512_avx2( void* XXH_RESTRICT acc,
                    const void* XXH_RESTRICT input,
                    const void* XXH_RESTRICT secret)
{
    XXH_ASSERT((((size_t)acc) & 31) == 0);
    {   __m256i* const xacc    =       (__m256i *) acc;

        const         __m256i* const xinput  = (const __m256i *) input;

        const         __m256i* const xsecret = (const __m256i *) secret;

        size_t i;
        for (i=0; i < XXH_STRIPE_LEN/sizeof(__m256i); i++) {

            __m256i const data_vec    = _mm256_loadu_si256    (xinput+i);

            __m256i const key_vec     = _mm256_loadu_si256   (xsecret+i);

            __m256i const data_key    = _mm256_xor_si256     (data_vec, key_vec);

            __m256i const data_key_lo = _mm256_shuffle_epi32 (data_key, _MM_SHUFFLE(0, 3, 0, 1));

            __m256i const product     = _mm256_mul_epu32     (data_key, data_key_lo);

            __m256i const data_swap = _mm256_shuffle_epi32(data_vec, _MM_SHUFFLE(1, 0, 3, 2));
            __m256i const sum       = _mm256_add_epi64(xacc[i], data_swap);

            xacc[i] = _mm256_add_epi64(product, sum);
    }   }
}
XXH_FORCE_INLINE XXH_TARGET_AVX2 XXH3_ACCUMULATE_TEMPLATE(avx2)

XXH_FORCE_INLINE XXH_TARGET_AVX2 void
XXH3_scrambleAcc_avx2(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
{
    XXH_ASSERT((((size_t)acc) & 31) == 0);
    {   __m256i* const xacc = (__m256i*) acc;

        const         __m256i* const xsecret = (const __m256i *) secret;
        const __m256i prime32 = _mm256_set1_epi32((int)XXH_PRIME32_1);

        size_t i;
        for (i=0; i < XXH_STRIPE_LEN/sizeof(__m256i); i++) {

            __m256i const acc_vec     = xacc[i];
            __m256i const shifted     = _mm256_srli_epi64    (acc_vec, 47);
            __m256i const data_vec    = _mm256_xor_si256     (acc_vec, shifted);

            __m256i const key_vec     = _mm256_loadu_si256   (xsecret+i);
            __m256i const data_key    = _mm256_xor_si256     (data_vec, key_vec);


            __m256i const data_key_hi = _mm256_shuffle_epi32 (data_key, _MM_SHUFFLE(0, 3, 0, 1));
            __m256i const prod_lo     = _mm256_mul_epu32     (data_key, prime32);
            __m256i const prod_hi     = _mm256_mul_epu32     (data_key_hi, prime32);
            xacc[i] = _mm256_add_epi64(prod_lo, _mm256_slli_epi64(prod_hi, 32));
        }
    }
}

XXH_FORCE_INLINE XXH_TARGET_AVX2 void XXH3_initCustomSecret_avx2(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
{
    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE & 31) == 0);
    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE / sizeof(__m256i)) == 6);
    XXH_STATIC_ASSERT(XXH_SEC_ALIGN <= 64);
    (void)(&XXH_writeLE64);
    XXH_PREFETCH(customSecret);
    {   __m256i const seed = _mm256_set_epi64x((xxh_i64)(0U - seed64), (xxh_i64)seed64, (xxh_i64)(0U - seed64), (xxh_i64)seed64);

        const __m256i* const src  = (const __m256i*) ((const void*) XXH3_kSecret);
              __m256i*       dest = (      __m256i*) customSecret;

#       if defined(__GNUC__) || defined(__clang__)

        XXH_COMPILER_GUARD(dest);
#       endif
        XXH_ASSERT(((size_t)src & 31) == 0);
        XXH_ASSERT(((size_t)dest & 31) == 0);


        dest[0] = _mm256_add_epi64(_mm256_load_si256(src+0), seed);
        dest[1] = _mm256_add_epi64(_mm256_load_si256(src+1), seed);
        dest[2] = _mm256_add_epi64(_mm256_load_si256(src+2), seed);
        dest[3] = _mm256_add_epi64(_mm256_load_si256(src+3), seed);
        dest[4] = _mm256_add_epi64(_mm256_load_si256(src+4), seed);
        dest[5] = _mm256_add_epi64(_mm256_load_si256(src+5), seed);
    }
}

#endif


#if (XXH_VECTOR == XXH_SSE2) || defined(XXH_X86DISPATCH)

#ifndef XXH_TARGET_SSE2
# define XXH_TARGET_SSE2
#endif

XXH_FORCE_INLINE XXH_TARGET_SSE2 void
XXH3_accumulate_512_sse2( void* XXH_RESTRICT acc,
                    const void* XXH_RESTRICT input,
                    const void* XXH_RESTRICT secret)
{

    XXH_ASSERT((((size_t)acc) & 15) == 0);
    {   __m128i* const xacc    =       (__m128i *) acc;

        const         __m128i* const xinput  = (const __m128i *) input;

        const         __m128i* const xsecret = (const __m128i *) secret;

        size_t i;
        for (i=0; i < XXH_STRIPE_LEN/sizeof(__m128i); i++) {

            __m128i const data_vec    = _mm_loadu_si128   (xinput+i);

            __m128i const key_vec     = _mm_loadu_si128   (xsecret+i);

            __m128i const data_key    = _mm_xor_si128     (data_vec, key_vec);

            __m128i const data_key_lo = _mm_shuffle_epi32 (data_key, _MM_SHUFFLE(0, 3, 0, 1));

            __m128i const product     = _mm_mul_epu32     (data_key, data_key_lo);

            __m128i const data_swap = _mm_shuffle_epi32(data_vec, _MM_SHUFFLE(1,0,3,2));
            __m128i const sum       = _mm_add_epi64(xacc[i], data_swap);

            xacc[i] = _mm_add_epi64(product, sum);
    }   }
}
XXH_FORCE_INLINE XXH_TARGET_SSE2 XXH3_ACCUMULATE_TEMPLATE(sse2)

XXH_FORCE_INLINE XXH_TARGET_SSE2 void
XXH3_scrambleAcc_sse2(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
{
    XXH_ASSERT((((size_t)acc) & 15) == 0);
    {   __m128i* const xacc = (__m128i*) acc;

        const         __m128i* const xsecret = (const __m128i *) secret;
        const __m128i prime32 = _mm_set1_epi32((int)XXH_PRIME32_1);

        size_t i;
        for (i=0; i < XXH_STRIPE_LEN/sizeof(__m128i); i++) {

            __m128i const acc_vec     = xacc[i];
            __m128i const shifted     = _mm_srli_epi64    (acc_vec, 47);
            __m128i const data_vec    = _mm_xor_si128     (acc_vec, shifted);

            __m128i const key_vec     = _mm_loadu_si128   (xsecret+i);
            __m128i const data_key    = _mm_xor_si128     (data_vec, key_vec);


            __m128i const data_key_hi = _mm_shuffle_epi32 (data_key, _MM_SHUFFLE(0, 3, 0, 1));
            __m128i const prod_lo     = _mm_mul_epu32     (data_key, prime32);
            __m128i const prod_hi     = _mm_mul_epu32     (data_key_hi, prime32);
            xacc[i] = _mm_add_epi64(prod_lo, _mm_slli_epi64(prod_hi, 32));
        }
    }
}

XXH_FORCE_INLINE XXH_TARGET_SSE2 void XXH3_initCustomSecret_sse2(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
{
    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE & 15) == 0);
    (void)(&XXH_writeLE64);
    {   int const nbRounds = XXH_SECRET_DEFAULT_SIZE / sizeof(__m128i);

#       if defined(_MSC_VER) && defined(_M_IX86) && _MSC_VER < 1900

        XXH_ALIGN(16) const xxh_i64 seed64x2[2] = { (xxh_i64)seed64, (xxh_i64)(0U - seed64) };
        __m128i const seed = _mm_load_si128((__m128i const*)seed64x2);
#       else
        __m128i const seed = _mm_set_epi64x((xxh_i64)(0U - seed64), (xxh_i64)seed64);
#       endif
        int i;

        const void* const src16 = XXH3_kSecret;
        __m128i* dst16 = (__m128i*) customSecret;
#       if defined(__GNUC__) || defined(__clang__)

        XXH_COMPILER_GUARD(dst16);
#       endif
        XXH_ASSERT(((size_t)src16 & 15) == 0);
        XXH_ASSERT(((size_t)dst16 & 15) == 0);

        for (i=0; i < nbRounds; ++i) {
            dst16[i] = _mm_add_epi64(_mm_load_si128((const __m128i *)src16+i), seed);
    }   }
}

#endif

#if (XXH_VECTOR == XXH_NEON)


XXH_FORCE_INLINE void
XXH3_scalarRound(void* XXH_RESTRICT acc, void const* XXH_RESTRICT input,
                 void const* XXH_RESTRICT secret, size_t lane);

XXH_FORCE_INLINE void
XXH3_scalarScrambleRound(void* XXH_RESTRICT acc,
                         void const* XXH_RESTRICT secret, size_t lane);


XXH_FORCE_INLINE void
XXH3_accumulate_512_neon( void* XXH_RESTRICT acc,
                    const void* XXH_RESTRICT input,
                    const void* XXH_RESTRICT secret)
{
    XXH_ASSERT((((size_t)acc) & 15) == 0);
    XXH_STATIC_ASSERT(XXH3_NEON_LANES > 0 && XXH3_NEON_LANES <= XXH_ACC_NB && XXH3_NEON_LANES % 2 == 0);
    {
        uint64x2_t* const xacc = (uint64x2_t *) acc;

        uint8_t const* const xinput = (const uint8_t *) input;
        uint8_t const* const xsecret  = (const uint8_t *) secret;

        size_t i;

        for (i = XXH3_NEON_LANES; i < XXH_ACC_NB; i++) {
            XXH3_scalarRound(acc, input, secret, i);
        }
        i = 0;
        for (; i+1 < XXH3_NEON_LANES / 2; i+=2) {
            uint64x2_t acc_vec1 = xacc[i];

            uint64x2_t data_vec1 = XXH_vld1q_u64(xinput  + (i * 16));

            uint64x2_t key_vec1  = XXH_vld1q_u64(xsecret + (i * 16));

            uint64x2_t acc_vec_21 = vextq_u64(data_vec1, data_vec1, 1);

            uint64x2_t data_key1 = veorq_u64(data_vec1, key_vec1);

            uint64x2_t acc_vec2 = xacc[i+1];

            uint64x2_t data_vec2 = XXH_vld1q_u64(xinput  + ((i+1) * 16));

            uint64x2_t key_vec2  = XXH_vld1q_u64(xsecret + ((i+1) * 16));

            uint64x2_t acc_vec_22 = vextq_u64(data_vec2, data_vec2, 1);

            uint64x2_t data_key2 = veorq_u64(data_vec2, key_vec2);


            uint32x4x2_t zipped = vuzpq_u32(vreinterpretq_u32_u64(data_key1), vreinterpretq_u32_u64(data_key2));
            uint32x4_t data_key_lo = zipped.val[0];
            uint32x4_t data_key_hi = zipped.val[1];


            acc_vec_21 = vmlal_u32 (acc_vec_21, vget_low_u32(data_key_lo), vget_low_u32(data_key_hi));
            XXH_COMPILER_GUARD_W(acc_vec_21);

            acc_vec1 = vaddq_u64 (acc_vec1, acc_vec_21);
            xacc[i] = acc_vec1;

            acc_vec_22 = vmlal_u32 (acc_vec_22, vget_high_u32(data_key_lo), vget_high_u32(data_key_hi));
            XXH_COMPILER_GUARD_W(acc_vec_22);

            acc_vec2 = vaddq_u64 (acc_vec2, acc_vec_22);
            xacc[i+1] = acc_vec2;
        }
        for (; i < XXH3_NEON_LANES / 2; i++) {
            uint64x2_t acc_vec = xacc[i];

            uint64x2_t data_vec = XXH_vld1q_u64(xinput  + (i * 16));

            uint64x2_t key_vec  = XXH_vld1q_u64(xsecret + (i * 16));
            uint64x2_t data_key;
            uint32x2_t data_key_lo, data_key_hi;

            uint64x2_t acc_vec_2 = vextq_u64(data_vec, data_vec, 1);

            data_key = veorq_u64(data_vec, key_vec);

            XXH_SPLIT_IN_PLACE(data_key, data_key_lo, data_key_hi);

            acc_vec_2 = vmlal_u32 (acc_vec_2, data_key_lo, data_key_hi);
            XXH_COMPILER_GUARD_W(acc_vec_2);

            acc_vec = vaddq_u64 (acc_vec, acc_vec_2);
            xacc[i] = acc_vec;
        }

    }
}
XXH_FORCE_INLINE XXH3_ACCUMULATE_TEMPLATE(neon)

XXH_FORCE_INLINE void
XXH3_scrambleAcc_neon(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
{
    XXH_ASSERT((((size_t)acc) & 15) == 0);

    {   uint64x2_t* xacc       = (uint64x2_t*) acc;
        uint8_t const* xsecret = (uint8_t const*) secret;
        uint32x2_t prime       = vdup_n_u32 (XXH_PRIME32_1);

        size_t i;

        for (i = XXH3_NEON_LANES; i < XXH_ACC_NB; i++) {
            XXH3_scalarScrambleRound(acc, secret, i);
        }
        for (i=0; i < XXH3_NEON_LANES / 2; i++) {

            uint64x2_t acc_vec  = xacc[i];
            uint64x2_t shifted  = vshrq_n_u64   (acc_vec, 47);
            uint64x2_t data_vec = veorq_u64     (acc_vec, shifted);


            uint64x2_t key_vec  = XXH_vld1q_u64 (xsecret + (i * 16));
            uint64x2_t data_key = veorq_u64     (data_vec, key_vec);


            uint32x2_t data_key_lo, data_key_hi;

            XXH_SPLIT_IN_PLACE(data_key, data_key_lo, data_key_hi);
            {
                uint64x2_t prod_hi = vmull_u32 (data_key_hi, prime);

                prod_hi = vshlq_n_u64(prod_hi, 32);

                xacc[i] = vmlal_u32(prod_hi, data_key_lo, prime);
            }
        }
    }
}

#endif

#if (XXH_VECTOR == XXH_VSX)

XXH_FORCE_INLINE void
XXH3_accumulate_512_vsx(  void* XXH_RESTRICT acc,
                    const void* XXH_RESTRICT input,
                    const void* XXH_RESTRICT secret)
{

    unsigned int* const xacc = (unsigned int*) acc;
    xxh_u64x2 const* const xinput   = (xxh_u64x2 const*) input;
    xxh_u64x2 const* const xsecret  = (xxh_u64x2 const*) secret;
    xxh_u64x2 const v32 = { 32, 32 };
    size_t i;
    for (i = 0; i < XXH_STRIPE_LEN / sizeof(xxh_u64x2); i++) {

        xxh_u64x2 const data_vec = XXH_vec_loadu(xinput + i);

        xxh_u64x2 const key_vec  = XXH_vec_loadu(xsecret + i);
        xxh_u64x2 const data_key = data_vec ^ key_vec;

        xxh_u32x4 const shuffled = (xxh_u32x4)vec_rl(data_key, v32);

        xxh_u64x2 const product  = XXH_vec_mulo((xxh_u32x4)data_key, shuffled);

        xxh_u64x2 acc_vec        = (xxh_u64x2)vec_xl(0, xacc + 4 * i);
        acc_vec += product;


#ifdef __s390x__
        acc_vec += vec_permi(data_vec, data_vec, 2);
#else
        acc_vec += vec_xxpermdi(data_vec, data_vec, 2);
#endif

        vec_xst((xxh_u32x4)acc_vec, 0, xacc + 4 * i);
    }
}
XXH_FORCE_INLINE XXH3_ACCUMULATE_TEMPLATE(vsx)

XXH_FORCE_INLINE void
XXH3_scrambleAcc_vsx(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
{
    XXH_ASSERT((((size_t)acc) & 15) == 0);

    {         xxh_u64x2* const xacc    =       (xxh_u64x2*) acc;
        const xxh_u64x2* const xsecret = (const xxh_u64x2*) secret;

        xxh_u64x2 const v32  = { 32, 32 };
        xxh_u64x2 const v47 = { 47, 47 };
        xxh_u32x4 const prime = { XXH_PRIME32_1, XXH_PRIME32_1, XXH_PRIME32_1, XXH_PRIME32_1 };
        size_t i;
        for (i = 0; i < XXH_STRIPE_LEN / sizeof(xxh_u64x2); i++) {

            xxh_u64x2 const acc_vec  = xacc[i];
            xxh_u64x2 const data_vec = acc_vec ^ (acc_vec >> v47);


            xxh_u64x2 const key_vec  = XXH_vec_loadu(xsecret + i);
            xxh_u64x2 const data_key = data_vec ^ key_vec;



            xxh_u64x2 const prod_even  = XXH_vec_mule((xxh_u32x4)data_key, prime);

            xxh_u64x2 const prod_odd  = XXH_vec_mulo((xxh_u32x4)data_key, prime);
            xacc[i] = prod_odd + (prod_even << v32);
    }   }
}

#endif

#if (XXH_VECTOR == XXH_SVE)

XXH_FORCE_INLINE void
XXH3_accumulate_512_sve( void* XXH_RESTRICT acc,
                   const void* XXH_RESTRICT input,
                   const void* XXH_RESTRICT secret)
{
    uint64_t *xacc = (uint64_t *)acc;
    const uint64_t *xinput = (const uint64_t *)(const void *)input;
    const uint64_t *xsecret = (const uint64_t *)(const void *)secret;
    svuint64_t kSwap = sveor_n_u64_z(svptrue_b64(), svindex_u64(0, 1), 1);
    uint64_t element_count = svcntd();
    if (element_count >= 8) {
        svbool_t mask = svptrue_pat_b64(SV_VL8);
        svuint64_t vacc = svld1_u64(mask, xacc);
        ACCRND(vacc, 0);
        svst1_u64(mask, xacc, vacc);
    } else if (element_count == 2) {
        svbool_t mask = svptrue_pat_b64(SV_VL2);
        svuint64_t acc0 = svld1_u64(mask, xacc + 0);
        svuint64_t acc1 = svld1_u64(mask, xacc + 2);
        svuint64_t acc2 = svld1_u64(mask, xacc + 4);
        svuint64_t acc3 = svld1_u64(mask, xacc + 6);
        ACCRND(acc0, 0);
        ACCRND(acc1, 2);
        ACCRND(acc2, 4);
        ACCRND(acc3, 6);
        svst1_u64(mask, xacc + 0, acc0);
        svst1_u64(mask, xacc + 2, acc1);
        svst1_u64(mask, xacc + 4, acc2);
        svst1_u64(mask, xacc + 6, acc3);
    } else {
        svbool_t mask = svptrue_pat_b64(SV_VL4);
        svuint64_t acc0 = svld1_u64(mask, xacc + 0);
        svuint64_t acc1 = svld1_u64(mask, xacc + 4);
        ACCRND(acc0, 0);
        ACCRND(acc1, 4);
        svst1_u64(mask, xacc + 0, acc0);
        svst1_u64(mask, xacc + 4, acc1);
    }
}

XXH_FORCE_INLINE void
XXH3_accumulate_sve(xxh_u64* XXH_RESTRICT acc,
               const xxh_u8* XXH_RESTRICT input,
               const xxh_u8* XXH_RESTRICT secret,
               size_t nbStripes)
{
    if (nbStripes != 0) {
        uint64_t *xacc = (uint64_t *)acc;
        const uint64_t *xinput = (const uint64_t *)(const void *)input;
        const uint64_t *xsecret = (const uint64_t *)(const void *)secret;
        svuint64_t kSwap = sveor_n_u64_z(svptrue_b64(), svindex_u64(0, 1), 1);
        uint64_t element_count = svcntd();
        if (element_count >= 8) {
            svbool_t mask = svptrue_pat_b64(SV_VL8);
            svuint64_t vacc = svld1_u64(mask, xacc + 0);
            do {

                svprfd(mask, xinput + 128, SV_PLDL1STRM);
                ACCRND(vacc, 0);
                xinput += 8;
                xsecret += 1;
                nbStripes--;
           } while (nbStripes != 0);

           svst1_u64(mask, xacc + 0, vacc);
        } else if (element_count == 2) {
            svbool_t mask = svptrue_pat_b64(SV_VL2);
            svuint64_t acc0 = svld1_u64(mask, xacc + 0);
            svuint64_t acc1 = svld1_u64(mask, xacc + 2);
            svuint64_t acc2 = svld1_u64(mask, xacc + 4);
            svuint64_t acc3 = svld1_u64(mask, xacc + 6);
            do {
                svprfd(mask, xinput + 128, SV_PLDL1STRM);
                ACCRND(acc0, 0);
                ACCRND(acc1, 2);
                ACCRND(acc2, 4);
                ACCRND(acc3, 6);
                xinput += 8;
                xsecret += 1;
                nbStripes--;
           } while (nbStripes != 0);

           svst1_u64(mask, xacc + 0, acc0);
           svst1_u64(mask, xacc + 2, acc1);
           svst1_u64(mask, xacc + 4, acc2);
           svst1_u64(mask, xacc + 6, acc3);
        } else {
            svbool_t mask = svptrue_pat_b64(SV_VL4);
            svuint64_t acc0 = svld1_u64(mask, xacc + 0);
            svuint64_t acc1 = svld1_u64(mask, xacc + 4);
            do {
                svprfd(mask, xinput + 128, SV_PLDL1STRM);
                ACCRND(acc0, 0);
                ACCRND(acc1, 4);
                xinput += 8;
                xsecret += 1;
                nbStripes--;
           } while (nbStripes != 0);

           svst1_u64(mask, xacc + 0, acc0);
           svst1_u64(mask, xacc + 4, acc1);
       }
    }
}

#endif




XXH_FORCE_INLINE void
XXH3_scalarRound(void* XXH_RESTRICT acc,
                 void const* XXH_RESTRICT input,
                 void const* XXH_RESTRICT secret,
                 size_t lane)
{
    xxh_u64* xacc = (xxh_u64*) acc;
    xxh_u8 const* xinput  = (xxh_u8 const*) input;
    xxh_u8 const* xsecret = (xxh_u8 const*) secret;
    XXH_ASSERT(lane < XXH_ACC_NB);
    XXH_ASSERT(((size_t)acc & (XXH_ACC_ALIGN-1)) == 0);
    {
        xxh_u64 const data_val = XXH_readLE64(xinput + lane * 8);
        xxh_u64 const data_key = data_val ^ XXH_readLE64(xsecret + lane * 8);
        xacc[lane ^ 1] += data_val;
        xacc[lane] += XXH_mult32to64(data_key & 0xFFFFFFFF, data_key >> 32);
    }
}


XXH_FORCE_INLINE void
XXH3_accumulate_512_scalar(void* XXH_RESTRICT acc,
                     const void* XXH_RESTRICT input,
                     const void* XXH_RESTRICT secret)
{
    size_t i;

#if defined(__GNUC__) && !defined(__clang__) \
  && (defined(__arm__) || defined(__thumb2__)) \
  && defined(__ARM_FEATURE_UNALIGNED)  \
  && XXH_SIZE_OPT <= 0
#  pragma GCC unroll 8
#endif
    for (i=0; i < XXH_ACC_NB; i++) {
        XXH3_scalarRound(acc, input, secret, i);
    }
}
XXH_FORCE_INLINE XXH3_ACCUMULATE_TEMPLATE(scalar)


XXH_FORCE_INLINE void
XXH3_scalarScrambleRound(void* XXH_RESTRICT acc,
                         void const* XXH_RESTRICT secret,
                         size_t lane)
{
    xxh_u64* const xacc = (xxh_u64*) acc;
    const xxh_u8* const xsecret = (const xxh_u8*) secret;
    XXH_ASSERT((((size_t)acc) & (XXH_ACC_ALIGN-1)) == 0);
    XXH_ASSERT(lane < XXH_ACC_NB);
    {
        xxh_u64 const key64 = XXH_readLE64(xsecret + lane * 8);
        xxh_u64 acc64 = xacc[lane];
        acc64 = XXH_xorshift64(acc64, 47);
        acc64 ^= key64;
        acc64 *= XXH_PRIME32_1;
        xacc[lane] = acc64;
    }
}


XXH_FORCE_INLINE void
XXH3_scrambleAcc_scalar(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
{
    size_t i;
    for (i=0; i < XXH_ACC_NB; i++) {
        XXH3_scalarScrambleRound(acc, secret, i);
    }
}

XXH_FORCE_INLINE void
XXH3_initCustomSecret_scalar(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
{

    const xxh_u8* kSecretPtr = XXH3_kSecret;
    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE & 15) == 0);

#if defined(__clang__) && defined(__aarch64__)

    XXH_COMPILER_GUARD(kSecretPtr);
#endif

    XXH_ASSERT(kSecretPtr == XXH3_kSecret);

    {   int const nbRounds = XXH_SECRET_DEFAULT_SIZE / 16;
        int i;
        for (i=0; i < nbRounds; i++) {

            xxh_u64 lo = XXH_readLE64(kSecretPtr + 16*i)     + seed64;
            xxh_u64 hi = XXH_readLE64(kSecretPtr + 16*i + 8) - seed64;
            XXH_writeLE64((xxh_u8*)customSecret + 16*i,     lo);
            XXH_writeLE64((xxh_u8*)customSecret + 16*i + 8, hi);
    }   }
}


typedef void (*XXH3_f_accumulate)(xxh_u64* XXH_RESTRICT, const xxh_u8* XXH_RESTRICT, const xxh_u8* XXH_RESTRICT, size_t);
typedef void (*XXH3_f_scrambleAcc)(void* XXH_RESTRICT, const void*);
typedef void (*XXH3_f_initCustomSecret)(void* XXH_RESTRICT, xxh_u64);


#if (XXH_VECTOR == XXH_AVX512)

#define XXH3_accumulate_512 XXH3_accumulate_512_avx512
#define XXH3_accumulate     XXH3_accumulate_avx512
#define XXH3_scrambleAcc    XXH3_scrambleAcc_avx512
#define XXH3_initCustomSecret XXH3_initCustomSecret_avx512

#elif (XXH_VECTOR == XXH_AVX2)

#define XXH3_accumulate_512 XXH3_accumulate_512_avx2
#define XXH3_accumulate     XXH3_accumulate_avx2
#define XXH3_scrambleAcc    XXH3_scrambleAcc_avx2
#define XXH3_initCustomSecret XXH3_initCustomSecret_avx2

#elif (XXH_VECTOR == XXH_SSE2)

#define XXH3_accumulate_512 XXH3_accumulate_512_sse2
#define XXH3_accumulate     XXH3_accumulate_sse2
#define XXH3_scrambleAcc    XXH3_scrambleAcc_sse2
#define XXH3_initCustomSecret XXH3_initCustomSecret_sse2

#elif (XXH_VECTOR == XXH_NEON)

#define XXH3_accumulate_512 XXH3_accumulate_512_neon
#define XXH3_accumulate     XXH3_accumulate_neon
#define XXH3_scrambleAcc    XXH3_scrambleAcc_neon
#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar

#elif (XXH_VECTOR == XXH_VSX)

#define XXH3_accumulate_512 XXH3_accumulate_512_vsx
#define XXH3_accumulate     XXH3_accumulate_vsx
#define XXH3_scrambleAcc    XXH3_scrambleAcc_vsx
#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar

#elif (XXH_VECTOR == XXH_SVE)
#define XXH3_accumulate_512 XXH3_accumulate_512_sve
#define XXH3_accumulate     XXH3_accumulate_sve
#define XXH3_scrambleAcc    XXH3_scrambleAcc_scalar
#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar

#else

#define XXH3_accumulate_512 XXH3_accumulate_512_scalar
#define XXH3_accumulate     XXH3_accumulate_scalar
#define XXH3_scrambleAcc    XXH3_scrambleAcc_scalar
#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar

#endif

#if XXH_SIZE_OPT >= 1
#  undef XXH3_initCustomSecret
#  define XXH3_initCustomSecret XXH3_initCustomSecret_scalar
#endif

XXH_FORCE_INLINE void
XXH3_hashLong_internal_loop(xxh_u64* XXH_RESTRICT acc,
                      const xxh_u8* XXH_RESTRICT input, size_t len,
                      const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
                            XXH3_f_accumulate f_acc,
                            XXH3_f_scrambleAcc f_scramble)
{
    size_t const nbStripesPerBlock = (secretSize - XXH_STRIPE_LEN) / XXH_SECRET_CONSUME_RATE;
    size_t const block_len = XXH_STRIPE_LEN * nbStripesPerBlock;
    size_t const nb_blocks = (len - 1) / block_len;

    size_t n;

    XXH_ASSERT(secretSize >= XXH3_SECRET_SIZE_MIN);

    for (n = 0; n < nb_blocks; n++) {
        f_acc(acc, input + n*block_len, secret, nbStripesPerBlock);
        f_scramble(acc, secret + secretSize - XXH_STRIPE_LEN);
    }


    XXH_ASSERT(len > XXH_STRIPE_LEN);
    {   size_t const nbStripes = ((len - 1) - (block_len * nb_blocks)) / XXH_STRIPE_LEN;
        XXH_ASSERT(nbStripes <= (secretSize / XXH_SECRET_CONSUME_RATE));
        f_acc(acc, input + nb_blocks*block_len, secret, nbStripes);


        {   const xxh_u8* const p = input + len - XXH_STRIPE_LEN;
#define XXH_SECRET_LASTACC_START 7
            XXH3_accumulate_512(acc, p, secret + secretSize - XXH_STRIPE_LEN - XXH_SECRET_LASTACC_START);
    }   }
}

XXH_FORCE_INLINE xxh_u64
XXH3_mix2Accs(const xxh_u64* XXH_RESTRICT acc, const xxh_u8* XXH_RESTRICT secret)
{
    return XXH3_mul128_fold64(
               acc[0] ^ XXH_readLE64(secret),
               acc[1] ^ XXH_readLE64(secret+8) );
}

static XXH64_hash_t
XXH3_mergeAccs(const xxh_u64* XXH_RESTRICT acc, const xxh_u8* XXH_RESTRICT secret, xxh_u64 start)
{
    xxh_u64 result64 = start;
    size_t i = 0;

    for (i = 0; i < 4; i++) {
        result64 += XXH3_mix2Accs(acc+2*i, secret + 16*i);
#if defined(__clang__)                                 \
    && (defined(__arm__) || defined(__thumb__))        \
    && (defined(__ARM_NEON) || defined(__ARM_NEON__))   \
    && !defined(XXH_ENABLE_AUTOVECTORIZE)

        XXH_COMPILER_GUARD(result64);
#endif
    }

    return XXH3_avalanche(result64);
}

#define XXH3_INIT_ACC { XXH_PRIME32_3, XXH_PRIME64_1, XXH_PRIME64_2, XXH_PRIME64_3, \
                        XXH_PRIME64_4, XXH_PRIME32_2, XXH_PRIME64_5, XXH_PRIME32_1 }

XXH_FORCE_INLINE XXH64_hash_t
XXH3_hashLong_64b_internal(const void* XXH_RESTRICT input, size_t len,
                           const void* XXH_RESTRICT secret, size_t secretSize,
                           XXH3_f_accumulate f_acc,
                           XXH3_f_scrambleAcc f_scramble)
{
    XXH_ALIGN(XXH_ACC_ALIGN) xxh_u64 acc[XXH_ACC_NB] = XXH3_INIT_ACC;

    XXH3_hashLong_internal_loop(acc, (const xxh_u8*)input, len, (const xxh_u8*)secret, secretSize, f_acc, f_scramble);


    XXH_STATIC_ASSERT(sizeof(acc) == 64);

#define XXH_SECRET_MERGEACCS_START 11
    XXH_ASSERT(secretSize >= sizeof(acc) + XXH_SECRET_MERGEACCS_START);
    return XXH3_mergeAccs(acc, (const xxh_u8*)secret + XXH_SECRET_MERGEACCS_START, (xxh_u64)len * XXH_PRIME64_1);
}


XXH_FORCE_INLINE XXH64_hash_t
XXH3_hashLong_64b_withSecret(const void* XXH_RESTRICT input, size_t len,
                             XXH64_hash_t seed64, const xxh_u8* XXH_RESTRICT secret, size_t secretLen)
{
    (void)seed64;
    return XXH3_hashLong_64b_internal(input, len, secret, secretLen, XXH3_accumulate, XXH3_scrambleAcc);
}


XXH_NO_INLINE XXH_PUREF XXH64_hash_t
XXH3_hashLong_64b_default(const void* XXH_RESTRICT input, size_t len,
                          XXH64_hash_t seed64, const xxh_u8* XXH_RESTRICT secret, size_t secretLen)
{
    (void)seed64; (void)secret; (void)secretLen;
    return XXH3_hashLong_64b_internal(input, len, XXH3_kSecret, sizeof(XXH3_kSecret), XXH3_accumulate, XXH3_scrambleAcc);
}


XXH_FORCE_INLINE XXH64_hash_t
XXH3_hashLong_64b_withSeed_internal(const void* input, size_t len,
                                    XXH64_hash_t seed,
                                    XXH3_f_accumulate f_acc,
                                    XXH3_f_scrambleAcc f_scramble,
                                    XXH3_f_initCustomSecret f_initSec)
{
#if XXH_SIZE_OPT <= 0
    if (seed == 0)
        return XXH3_hashLong_64b_internal(input, len,
                                          XXH3_kSecret, sizeof(XXH3_kSecret),
                                          f_acc, f_scramble);
#endif
    {   XXH_ALIGN(XXH_SEC_ALIGN) xxh_u8 secret[XXH_SECRET_DEFAULT_SIZE];
        f_initSec(secret, seed);
        return XXH3_hashLong_64b_internal(input, len, secret, sizeof(secret),
                                          f_acc, f_scramble);
    }
}


XXH_NO_INLINE XXH64_hash_t
XXH3_hashLong_64b_withSeed(const void* XXH_RESTRICT input, size_t len,
                           XXH64_hash_t seed, const xxh_u8* XXH_RESTRICT secret, size_t secretLen)
{
    (void)secret; (void)secretLen;
    return XXH3_hashLong_64b_withSeed_internal(input, len, seed,
                XXH3_accumulate, XXH3_scrambleAcc, XXH3_initCustomSecret);
}


typedef XXH64_hash_t (*XXH3_hashLong64_f)(const void* XXH_RESTRICT, size_t,
                                          XXH64_hash_t, const xxh_u8* XXH_RESTRICT, size_t);

XXH_FORCE_INLINE XXH64_hash_t
XXH3_64bits_internal(const void* XXH_RESTRICT input, size_t len,
                     XXH64_hash_t seed64, const void* XXH_RESTRICT secret, size_t secretLen,
                     XXH3_hashLong64_f f_hashLong)
{
    XXH_ASSERT(secretLen >= XXH3_SECRET_SIZE_MIN);

    if (len <= 16)
        return XXH3_len_0to16_64b((const xxh_u8*)input, len, (const xxh_u8*)secret, seed64);
    if (len <= 128)
        return XXH3_len_17to128_64b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
    if (len <= XXH3_MIDSIZE_MAX)
        return XXH3_len_129to240_64b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
    return f_hashLong(input, len, seed64, (const xxh_u8*)secret, secretLen);
}





XXH_PUBLIC_API XXH64_hash_t XXH3_64bits(const void* input, size_t length)
{
    return XXH3_64bits_internal(input, length, 0, XXH3_kSecret, sizeof(XXH3_kSecret), XXH3_hashLong_64b_default);
}


XXH_PUBLIC_API XXH64_hash_t
XXH3_64bits_withSecret(const void* input, size_t length, const void* secret, size_t secretSize)
{
    return XXH3_64bits_internal(input, length, 0, secret, secretSize, XXH3_hashLong_64b_withSecret);
}


XXH_PUBLIC_API XXH64_hash_t
XXH3_64bits_withSeed(const void* input, size_t length, XXH64_hash_t seed)
{
    return XXH3_64bits_internal(input, length, seed, XXH3_kSecret, sizeof(XXH3_kSecret), XXH3_hashLong_64b_withSeed);
}

XXH_PUBLIC_API XXH64_hash_t
XXH3_64bits_withSecretandSeed(const void* input, size_t length, const void* secret, size_t secretSize, XXH64_hash_t seed)
{
    if (length <= XXH3_MIDSIZE_MAX)
        return XXH3_64bits_internal(input, length, seed, XXH3_kSecret, sizeof(XXH3_kSecret), NULL);
    return XXH3_hashLong_64b_withSecret(input, length, seed, (const xxh_u8*)secret, secretSize);
}



#ifndef XXH_NO_STREAM

static XXH_MALLOCF void* XXH_alignedMalloc(size_t s, size_t align)
{
    XXH_ASSERT(align <= 128 && align >= 8);
    XXH_ASSERT((align & (align-1)) == 0);
    XXH_ASSERT(s != 0 && s < (s + align));
    {
        xxh_u8* base = (xxh_u8*)XXH_malloc(s + align);
        if (base != NULL) {

            size_t offset = align - ((size_t)base & (align - 1));

            xxh_u8* ptr = base + offset;

            XXH_ASSERT((size_t)ptr % align == 0);


            ptr[-1] = (xxh_u8)offset;
            return ptr;
        }
        return NULL;
    }
}

static void XXH_alignedFree(void* p)
{
    if (p != NULL) {
        xxh_u8* ptr = (xxh_u8*)p;

        xxh_u8 offset = ptr[-1];

        xxh_u8* base = ptr - offset;
        XXH_free(base);
    }
}

XXH_PUBLIC_API XXH3_state_t* XXH3_createState(void)
{
    XXH3_state_t* const state = (XXH3_state_t*)XXH_alignedMalloc(sizeof(XXH3_state_t), 64);
    if (state==NULL) return NULL;
    XXH3_INITSTATE(state);
    return state;
}


XXH_PUBLIC_API XXH_errorcode XXH3_freeState(XXH3_state_t* statePtr)
{
    XXH_alignedFree(statePtr);
    return XXH_OK;
}


XXH_PUBLIC_API void
XXH3_copyState(XXH3_state_t* dst_state, const XXH3_state_t* src_state)
{
    XXH_memcpy(dst_state, src_state, sizeof(*dst_state));
}

static void
XXH3_reset_internal(XXH3_state_t* statePtr,
                    XXH64_hash_t seed,
                    const void* secret, size_t secretSize)
{
    size_t const initStart = offsetof(XXH3_state_t, bufferedSize);
    size_t const initLength = offsetof(XXH3_state_t, nbStripesPerBlock) - initStart;
    XXH_ASSERT(offsetof(XXH3_state_t, nbStripesPerBlock) > initStart);
    XXH_ASSERT(statePtr != NULL);

    memset((char*)statePtr + initStart, 0, initLength);
    statePtr->acc[0] = XXH_PRIME32_3;
    statePtr->acc[1] = XXH_PRIME64_1;
    statePtr->acc[2] = XXH_PRIME64_2;
    statePtr->acc[3] = XXH_PRIME64_3;
    statePtr->acc[4] = XXH_PRIME64_4;
    statePtr->acc[5] = XXH_PRIME32_2;
    statePtr->acc[6] = XXH_PRIME64_5;
    statePtr->acc[7] = XXH_PRIME32_1;
    statePtr->seed = seed;
    statePtr->useSeed = (seed != 0);
    statePtr->extSecret = (const unsigned char*)secret;
    XXH_ASSERT(secretSize >= XXH3_SECRET_SIZE_MIN);
    statePtr->secretLimit = secretSize - XXH_STRIPE_LEN;
    statePtr->nbStripesPerBlock = statePtr->secretLimit / XXH_SECRET_CONSUME_RATE;
}


XXH_PUBLIC_API XXH_errorcode
XXH3_64bits_reset(XXH3_state_t* statePtr)
{
    if (statePtr == NULL) return XXH_ERROR;
    XXH3_reset_internal(statePtr, 0, XXH3_kSecret, XXH_SECRET_DEFAULT_SIZE);
    return XXH_OK;
}


XXH_PUBLIC_API XXH_errorcode
XXH3_64bits_reset_withSecret(XXH3_state_t* statePtr, const void* secret, size_t secretSize)
{
    if (statePtr == NULL) return XXH_ERROR;
    XXH3_reset_internal(statePtr, 0, secret, secretSize);
    if (secret == NULL) return XXH_ERROR;
    if (secretSize < XXH3_SECRET_SIZE_MIN) return XXH_ERROR;
    return XXH_OK;
}


XXH_PUBLIC_API XXH_errorcode
XXH3_64bits_reset_withSeed(XXH3_state_t* statePtr, XXH64_hash_t seed)
{
    if (statePtr == NULL) return XXH_ERROR;
    if (seed==0) return XXH3_64bits_reset(statePtr);
    if ((seed != statePtr->seed) || (statePtr->extSecret != NULL))
        XXH3_initCustomSecret(statePtr->customSecret, seed);
    XXH3_reset_internal(statePtr, seed, NULL, XXH_SECRET_DEFAULT_SIZE);
    return XXH_OK;
}


XXH_PUBLIC_API XXH_errorcode
XXH3_64bits_reset_withSecretandSeed(XXH3_state_t* statePtr, const void* secret, size_t secretSize, XXH64_hash_t seed64)
{
    if (statePtr == NULL) return XXH_ERROR;
    if (secret == NULL) return XXH_ERROR;
    if (secretSize < XXH3_SECRET_SIZE_MIN) return XXH_ERROR;
    XXH3_reset_internal(statePtr, seed64, secret, secretSize);
    statePtr->useSeed = 1;
    return XXH_OK;
}


XXH_FORCE_INLINE void
XXH3_consumeStripes(xxh_u64* XXH_RESTRICT acc,
                    size_t* XXH_RESTRICT nbStripesSoFarPtr, size_t nbStripesPerBlock,
                    const xxh_u8* XXH_RESTRICT input, size_t nbStripes,
                    const xxh_u8* XXH_RESTRICT secret, size_t secretLimit,
                    XXH3_f_accumulate f_acc,
                    XXH3_f_scrambleAcc f_scramble)
{
    XXH_ASSERT(nbStripes <= nbStripesPerBlock);
    XXH_ASSERT(*nbStripesSoFarPtr < nbStripesPerBlock);
    if (nbStripesPerBlock - *nbStripesSoFarPtr <= nbStripes) {

        size_t const nbStripesToEndofBlock = nbStripesPerBlock - *nbStripesSoFarPtr;
        size_t const nbStripesAfterBlock = nbStripes - nbStripesToEndofBlock;
        f_acc(acc, input, secret + nbStripesSoFarPtr[0] * XXH_SECRET_CONSUME_RATE, nbStripesToEndofBlock);
        f_scramble(acc, secret + secretLimit);
        f_acc(acc, input + nbStripesToEndofBlock * XXH_STRIPE_LEN, secret, nbStripesAfterBlock);
        *nbStripesSoFarPtr = nbStripesAfterBlock;
    } else {
        f_acc(acc, input, secret + nbStripesSoFarPtr[0] * XXH_SECRET_CONSUME_RATE, nbStripes);
        *nbStripesSoFarPtr += nbStripes;
    }
}

#ifndef XXH3_STREAM_USE_STACK
# if XXH_SIZE_OPT <= 0 && !defined(__clang__)
#   define XXH3_STREAM_USE_STACK 1
# endif
#endif

XXH_FORCE_INLINE XXH_errorcode
XXH3_update(XXH3_state_t* XXH_RESTRICT const state,
            const xxh_u8* XXH_RESTRICT input, size_t len,
            XXH3_f_accumulate f_acc,
            XXH3_f_scrambleAcc f_scramble)
{
    if (input==NULL) {
        XXH_ASSERT(len == 0);
        return XXH_OK;
    }

    XXH_ASSERT(state != NULL);
    {   const xxh_u8* const bEnd = input + len;
        const unsigned char* const secret = (state->extSecret == NULL) ? state->customSecret : state->extSecret;
#if defined(XXH3_STREAM_USE_STACK) && XXH3_STREAM_USE_STACK >= 1

        XXH_ALIGN(XXH_ACC_ALIGN) xxh_u64 acc[8]; memcpy(acc, state->acc, sizeof(acc));
#else
        xxh_u64* XXH_RESTRICT const acc = state->acc;
#endif
        state->totalLen += len;
        XXH_ASSERT(state->bufferedSize <= XXH3_INTERNALBUFFER_SIZE);


        if (state->bufferedSize + len <= XXH3_INTERNALBUFFER_SIZE) {
            XXH_memcpy(state->buffer + state->bufferedSize, input, len);
            state->bufferedSize += (XXH32_hash_t)len;
            return XXH_OK;
        }


#define XXH3_INTERNALBUFFER_STRIPES (XXH3_INTERNALBUFFER_SIZE / XXH_STRIPE_LEN)
        XXH_STATIC_ASSERT(XXH3_INTERNALBUFFER_SIZE % XXH_STRIPE_LEN == 0);   

        
        if (state->bufferedSize) {
            size_t const loadSize = XXH3_INTERNALBUFFER_SIZE - state->bufferedSize;
            XXH_memcpy(state->buffer + state->bufferedSize, input, loadSize);
            input += loadSize;
            XXH3_consumeStripes(acc,
                               &state->nbStripesSoFar, state->nbStripesPerBlock,
                                state->buffer, XXH3_INTERNALBUFFER_STRIPES,
                                secret, state->secretLimit,
                                f_acc, f_scramble);
            state->bufferedSize = 0;
        }
        XXH_ASSERT(input < bEnd);

        
        if ((size_t)(bEnd - input) > state->nbStripesPerBlock * XXH_STRIPE_LEN) {
            size_t nbStripes = (size_t)(bEnd - 1 - input) / XXH_STRIPE_LEN;
            XXH_ASSERT(state->nbStripesPerBlock >= state->nbStripesSoFar);
            
            {   size_t const nbStripesToEnd = state->nbStripesPerBlock - state->nbStripesSoFar;
                XXH_ASSERT(nbStripesToEnd <= nbStripes);
                f_acc(acc, input, secret + state->nbStripesSoFar * XXH_SECRET_CONSUME_RATE, nbStripesToEnd);
                f_scramble(acc, secret + state->secretLimit);
                state->nbStripesSoFar = 0;
                input += nbStripesToEnd * XXH_STRIPE_LEN;
                nbStripes -= nbStripesToEnd;
            }
            
            while(nbStripes >= state->nbStripesPerBlock) {
                f_acc(acc, input, secret, state->nbStripesPerBlock);
                f_scramble(acc, secret + state->secretLimit);
                input += state->nbStripesPerBlock * XXH_STRIPE_LEN;
                nbStripes -= state->nbStripesPerBlock;
            }
            
            f_acc(acc, input, secret, nbStripes);
            input += nbStripes * XXH_STRIPE_LEN;
            XXH_ASSERT(input < bEnd);  
            state->nbStripesSoFar = nbStripes;
            
            XXH_memcpy(state->buffer + sizeof(state->buffer) - XXH_STRIPE_LEN, input - XXH_STRIPE_LEN, XXH_STRIPE_LEN);
            XXH_ASSERT(bEnd - input <= XXH_STRIPE_LEN);
        } else {
            
            
            if (bEnd - input > XXH3_INTERNALBUFFER_SIZE) {
                const xxh_u8* const limit = bEnd - XXH3_INTERNALBUFFER_SIZE;
                do {
                    XXH3_consumeStripes(acc,
                                       &state->nbStripesSoFar, state->nbStripesPerBlock,
                                        input, XXH3_INTERNALBUFFER_STRIPES,
                                        secret, state->secretLimit,
                                        f_acc, f_scramble);
                    input += XXH3_INTERNALBUFFER_SIZE;
                } while (input<limit);
                
                XXH_memcpy(state->buffer + sizeof(state->buffer) - XXH_STRIPE_LEN, input - XXH_STRIPE_LEN, XXH_STRIPE_LEN);
            }
        }

        
        XXH_ASSERT(input < bEnd);
        XXH_ASSERT(bEnd - input <= XXH3_INTERNALBUFFER_SIZE);
        XXH_ASSERT(state->bufferedSize == 0);
        XXH_memcpy(state->buffer, input, (size_t)(bEnd-input));
        state->bufferedSize = (XXH32_hash_t)(bEnd-input);
#if defined(XXH3_STREAM_USE_STACK) && XXH3_STREAM_USE_STACK >= 1
        
        memcpy(state->acc, acc, sizeof(acc));
#endif
    }

    return XXH_OK;
}


XXH_PUBLIC_API XXH_errorcode
XXH3_64bits_update(XXH3_state_t* state, const void* input, size_t len)
{
    return XXH3_update(state, (const xxh_u8*)input, len,
                       XXH3_accumulate, XXH3_scrambleAcc);
}


XXH_FORCE_INLINE void
XXH3_digest_long (XXH64_hash_t* acc,
                  const XXH3_state_t* state,
                  const unsigned char* secret)
{
    
    XXH_memcpy(acc, state->acc, sizeof(state->acc));
    if (state->bufferedSize >= XXH_STRIPE_LEN) {
        size_t const nbStripes = (state->bufferedSize - 1) / XXH_STRIPE_LEN;
        size_t nbStripesSoFar = state->nbStripesSoFar;
        XXH3_consumeStripes(acc,
                           &nbStripesSoFar, state->nbStripesPerBlock,
                            state->buffer, nbStripes,
                            secret, state->secretLimit,
                            XXH3_accumulate, XXH3_scrambleAcc);
        
        XXH3_accumulate_512(acc,
                            state->buffer + state->bufferedSize - XXH_STRIPE_LEN,
                            secret + state->secretLimit - XXH_SECRET_LASTACC_START);
    } else {  
        xxh_u8 lastStripe[XXH_STRIPE_LEN];
        size_t const catchupSize = XXH_STRIPE_LEN - state->bufferedSize;
        XXH_ASSERT(state->bufferedSize > 0);  
        XXH_memcpy(lastStripe, state->buffer + sizeof(state->buffer) - catchupSize, catchupSize);
        XXH_memcpy(lastStripe + catchupSize, state->buffer, state->bufferedSize);
        XXH3_accumulate_512(acc,
                            lastStripe,
                            secret + state->secretLimit - XXH_SECRET_LASTACC_START);
    }
}


XXH_PUBLIC_API XXH64_hash_t XXH3_64bits_digest (const XXH3_state_t* state)
{
    const unsigned char* const secret = (state->extSecret == NULL) ? state->customSecret : state->extSecret;
    if (state->totalLen > XXH3_MIDSIZE_MAX) {
        XXH_ALIGN(XXH_ACC_ALIGN) XXH64_hash_t acc[XXH_ACC_NB];
        XXH3_digest_long(acc, state, secret);
        return XXH3_mergeAccs(acc,
                              secret + XXH_SECRET_MERGEACCS_START,
                              (xxh_u64)state->totalLen * XXH_PRIME64_1);
    }
    
    if (state->useSeed)
        return XXH3_64bits_withSeed(state->buffer, (size_t)state->totalLen, state->seed);
    return XXH3_64bits_withSecret(state->buffer, (size_t)(state->totalLen),
                                  secret, state->secretLimit + XXH_STRIPE_LEN);
}
#endif 




XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
XXH3_len_1to3_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    
    XXH_ASSERT(input != NULL);
    XXH_ASSERT(1 <= len && len <= 3);
    XXH_ASSERT(secret != NULL);
    
    {   xxh_u8 const c1 = input[0];
        xxh_u8 const c2 = input[len >> 1];
        xxh_u8 const c3 = input[len - 1];
        xxh_u32 const combinedl = ((xxh_u32)c1 <<16) | ((xxh_u32)c2 << 24)
                                | ((xxh_u32)c3 << 0) | ((xxh_u32)len << 8);
        xxh_u32 const combinedh = XXH_rotl32(XXH_swap32(combinedl), 13);
        xxh_u64 const bitflipl = (XXH_readLE32(secret) ^ XXH_readLE32(secret+4)) + seed;
        xxh_u64 const bitfliph = (XXH_readLE32(secret+8) ^ XXH_readLE32(secret+12)) - seed;
        xxh_u64 const keyed_lo = (xxh_u64)combinedl ^ bitflipl;
        xxh_u64 const keyed_hi = (xxh_u64)combinedh ^ bitfliph;
        XXH128_hash_t h128;
        h128.low64  = XXH64_avalanche(keyed_lo);
        h128.high64 = XXH64_avalanche(keyed_hi);
        return h128;
    }
}

XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
XXH3_len_4to8_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    XXH_ASSERT(input != NULL);
    XXH_ASSERT(secret != NULL);
    XXH_ASSERT(4 <= len && len <= 8);
    seed ^= (xxh_u64)XXH_swap32((xxh_u32)seed) << 32;
    {   xxh_u32 const input_lo = XXH_readLE32(input);
        xxh_u32 const input_hi = XXH_readLE32(input + len - 4);
        xxh_u64 const input_64 = input_lo + ((xxh_u64)input_hi << 32);
        xxh_u64 const bitflip = (XXH_readLE64(secret+16) ^ XXH_readLE64(secret+24)) + seed;
        xxh_u64 const keyed = input_64 ^ bitflip;

        
        XXH128_hash_t m128 = XXH_mult64to128(keyed, XXH_PRIME64_1 + (len << 2));

        m128.high64 += (m128.low64 << 1);
        m128.low64  ^= (m128.high64 >> 3);

        m128.low64   = XXH_xorshift64(m128.low64, 35);
        m128.low64  *= 0x9FB21C651E98DF25ULL;
        m128.low64   = XXH_xorshift64(m128.low64, 28);
        m128.high64  = XXH3_avalanche(m128.high64);
        return m128;
    }
}

XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
XXH3_len_9to16_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    XXH_ASSERT(input != NULL);
    XXH_ASSERT(secret != NULL);
    XXH_ASSERT(9 <= len && len <= 16);
    {   xxh_u64 const bitflipl = (XXH_readLE64(secret+32) ^ XXH_readLE64(secret+40)) - seed;
        xxh_u64 const bitfliph = (XXH_readLE64(secret+48) ^ XXH_readLE64(secret+56)) + seed;
        xxh_u64 const input_lo = XXH_readLE64(input);
        xxh_u64       input_hi = XXH_readLE64(input + len - 8);
        XXH128_hash_t m128 = XXH_mult64to128(input_lo ^ input_hi ^ bitflipl, XXH_PRIME64_1);
        
        m128.low64 += (xxh_u64)(len - 1) << 54;
        input_hi   ^= bitfliph;
        
        if (sizeof(void *) < sizeof(xxh_u64)) { 
            
            m128.high64 += (input_hi & 0xFFFFFFFF00000000ULL) + XXH_mult32to64((xxh_u32)input_hi, XXH_PRIME32_2);
        } else {
            
            m128.high64 += input_hi + XXH_mult32to64((xxh_u32)input_hi, XXH_PRIME32_2 - 1);
        }
        
        m128.low64  ^= XXH_swap64(m128.high64);

        {   
            XXH128_hash_t h128 = XXH_mult64to128(m128.low64, XXH_PRIME64_2);
            h128.high64 += m128.high64 * XXH_PRIME64_2;

            h128.low64   = XXH3_avalanche(h128.low64);
            h128.high64  = XXH3_avalanche(h128.high64);
            return h128;
    }   }
}


XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
XXH3_len_0to16_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
{
    XXH_ASSERT(len <= 16);
    {   if (len > 8) return XXH3_len_9to16_128b(input, len, secret, seed);
        if (len >= 4) return XXH3_len_4to8_128b(input, len, secret, seed);
        if (len) return XXH3_len_1to3_128b(input, len, secret, seed);
        {   XXH128_hash_t h128;
            xxh_u64 const bitflipl = XXH_readLE64(secret+64) ^ XXH_readLE64(secret+72);
            xxh_u64 const bitfliph = XXH_readLE64(secret+80) ^ XXH_readLE64(secret+88);
            h128.low64 = XXH64_avalanche(seed ^ bitflipl);
            h128.high64 = XXH64_avalanche( seed ^ bitfliph);
            return h128;
    }   }
}


XXH_FORCE_INLINE XXH128_hash_t
XXH128_mix32B(XXH128_hash_t acc, const xxh_u8* input_1, const xxh_u8* input_2,
              const xxh_u8* secret, XXH64_hash_t seed)
{
    acc.low64  += XXH3_mix16B (input_1, secret+0, seed);
    acc.low64  ^= XXH_readLE64(input_2) + XXH_readLE64(input_2 + 8);
    acc.high64 += XXH3_mix16B (input_2, secret+16, seed);
    acc.high64 ^= XXH_readLE64(input_1) + XXH_readLE64(input_1 + 8);
    return acc;
}


XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
XXH3_len_17to128_128b(const xxh_u8* XXH_RESTRICT input, size_t len,
                      const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
                      XXH64_hash_t seed)
{
    XXH_ASSERT(secretSize >= XXH3_SECRET_SIZE_MIN); (void)secretSize;
    XXH_ASSERT(16 < len && len <= 128);

    {   XXH128_hash_t acc;
        acc.low64 = len * XXH_PRIME64_1;
        acc.high64 = 0;

#if XXH_SIZE_OPT >= 1
        {
            
            size_t i = (len - 1) / 32;
            do {
                acc = XXH128_mix32B(acc, input+16*i, input+len-16*(i+1), secret+32*i, seed);
            } while (i-- != 0);
        }
#else
        if (len > 32) {
            if (len > 64) {
                if (len > 96) {
                    acc = XXH128_mix32B(acc, input+48, input+len-64, secret+96, seed);
                }
                acc = XXH128_mix32B(acc, input+32, input+len-48, secret+64, seed);
            }
            acc = XXH128_mix32B(acc, input+16, input+len-32, secret+32, seed);
        }
        acc = XXH128_mix32B(acc, input, input+len-16, secret, seed);
#endif
        {   XXH128_hash_t h128;
            h128.low64  = acc.low64 + acc.high64;
            h128.high64 = (acc.low64    * XXH_PRIME64_1)
                        + (acc.high64   * XXH_PRIME64_4)
                        + ((len - seed) * XXH_PRIME64_2);
            h128.low64  = XXH3_avalanche(h128.low64);
            h128.high64 = (XXH64_hash_t)0 - XXH3_avalanche(h128.high64);
            return h128;
        }
    }
}

XXH_NO_INLINE XXH_PUREF XXH128_hash_t
XXH3_len_129to240_128b(const xxh_u8* XXH_RESTRICT input, size_t len,
                       const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
                       XXH64_hash_t seed)
{
    XXH_ASSERT(secretSize >= XXH3_SECRET_SIZE_MIN); (void)secretSize;
    XXH_ASSERT(128 < len && len <= XXH3_MIDSIZE_MAX);

    {   XXH128_hash_t acc;
        int const nbRounds = (int)len / 32;
        int i;
        acc.low64 = len * XXH_PRIME64_1;
        acc.high64 = 0;
        for (i=0; i<4; i++) {
            acc = XXH128_mix32B(acc,
                                input  + (32 * i),
                                input  + (32 * i) + 16,
                                secret + (32 * i),
                                seed);
        }
        acc.low64 = XXH3_avalanche(acc.low64);
        acc.high64 = XXH3_avalanche(acc.high64);
        XXH_ASSERT(nbRounds >= 4);
        for (i=4 ; i < nbRounds; i++) {
            acc = XXH128_mix32B(acc,
                                input + (32 * i),
                                input + (32 * i) + 16,
                                secret + XXH3_MIDSIZE_STARTOFFSET + (32 * (i - 4)),
                                seed);
        }
        
        acc = XXH128_mix32B(acc,
                            input + len - 16,
                            input + len - 32,
                            secret + XXH3_SECRET_SIZE_MIN - XXH3_MIDSIZE_LASTOFFSET - 16,
                            0ULL - seed);

        {   XXH128_hash_t h128;
            h128.low64  = acc.low64 + acc.high64;
            h128.high64 = (acc.low64    * XXH_PRIME64_1)
                        + (acc.high64   * XXH_PRIME64_4)
                        + ((len - seed) * XXH_PRIME64_2);
            h128.low64  = XXH3_avalanche(h128.low64);
            h128.high64 = (XXH64_hash_t)0 - XXH3_avalanche(h128.high64);
            return h128;
        }
    }
}

XXH_FORCE_INLINE XXH128_hash_t
XXH3_hashLong_128b_internal(const void* XXH_RESTRICT input, size_t len,
                            const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
                            XXH3_f_accumulate f_acc,
                            XXH3_f_scrambleAcc f_scramble)
{
    XXH_ALIGN(XXH_ACC_ALIGN) xxh_u64 acc[XXH_ACC_NB] = XXH3_INIT_ACC;

    XXH3_hashLong_internal_loop(acc, (const xxh_u8*)input, len, secret, secretSize, f_acc, f_scramble);

    
    XXH_STATIC_ASSERT(sizeof(acc) == 64);
    XXH_ASSERT(secretSize >= sizeof(acc) + XXH_SECRET_MERGEACCS_START);
    {   XXH128_hash_t h128;
        h128.low64  = XXH3_mergeAccs(acc,
                                     secret + XXH_SECRET_MERGEACCS_START,
                                     (xxh_u64)len * XXH_PRIME64_1);
        h128.high64 = XXH3_mergeAccs(acc,
                                     secret + secretSize
                                            - sizeof(acc) - XXH_SECRET_MERGEACCS_START,
                                     ~((xxh_u64)len * XXH_PRIME64_2));
        return h128;
    }
}


XXH_NO_INLINE XXH_PUREF XXH128_hash_t
XXH3_hashLong_128b_default(const void* XXH_RESTRICT input, size_t len,
                           XXH64_hash_t seed64,
                           const void* XXH_RESTRICT secret, size_t secretLen)
{
    (void)seed64; (void)secret; (void)secretLen;
    return XXH3_hashLong_128b_internal(input, len, XXH3_kSecret, sizeof(XXH3_kSecret),
                                       XXH3_accumulate, XXH3_scrambleAcc);
}


XXH_FORCE_INLINE XXH128_hash_t
XXH3_hashLong_128b_withSecret(const void* XXH_RESTRICT input, size_t len,
                              XXH64_hash_t seed64,
                              const void* XXH_RESTRICT secret, size_t secretLen)
{
    (void)seed64;
    return XXH3_hashLong_128b_internal(input, len, (const xxh_u8*)secret, secretLen,
                                       XXH3_accumulate, XXH3_scrambleAcc);
}

XXH_FORCE_INLINE XXH128_hash_t
XXH3_hashLong_128b_withSeed_internal(const void* XXH_RESTRICT input, size_t len,
                                XXH64_hash_t seed64,
                                XXH3_f_accumulate f_acc,
                                XXH3_f_scrambleAcc f_scramble,
                                XXH3_f_initCustomSecret f_initSec)
{
    if (seed64 == 0)
        return XXH3_hashLong_128b_internal(input, len,
                                           XXH3_kSecret, sizeof(XXH3_kSecret),
                                           f_acc, f_scramble);
    {   XXH_ALIGN(XXH_SEC_ALIGN) xxh_u8 secret[XXH_SECRET_DEFAULT_SIZE];
        f_initSec(secret, seed64);
        return XXH3_hashLong_128b_internal(input, len, (const xxh_u8*)secret, sizeof(secret),
                                           f_acc, f_scramble);
    }
}


XXH_NO_INLINE XXH128_hash_t
XXH3_hashLong_128b_withSeed(const void* input, size_t len,
                            XXH64_hash_t seed64, const void* XXH_RESTRICT secret, size_t secretLen)
{
    (void)secret; (void)secretLen;
    return XXH3_hashLong_128b_withSeed_internal(input, len, seed64,
                XXH3_accumulate, XXH3_scrambleAcc, XXH3_initCustomSecret);
}

typedef XXH128_hash_t (*XXH3_hashLong128_f)(const void* XXH_RESTRICT, size_t,
                                            XXH64_hash_t, const void* XXH_RESTRICT, size_t);

XXH_FORCE_INLINE XXH128_hash_t
XXH3_128bits_internal(const void* input, size_t len,
                      XXH64_hash_t seed64, const void* XXH_RESTRICT secret, size_t secretLen,
                      XXH3_hashLong128_f f_hl128)
{
    XXH_ASSERT(secretLen >= XXH3_SECRET_SIZE_MIN);
    
    if (len <= 16)
        return XXH3_len_0to16_128b((const xxh_u8*)input, len, (const xxh_u8*)secret, seed64);
    if (len <= 128)
        return XXH3_len_17to128_128b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
    if (len <= XXH3_MIDSIZE_MAX)
        return XXH3_len_129to240_128b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
    return f_hl128(input, len, seed64, secret, secretLen);
}





XXH_PUBLIC_API XXH128_hash_t XXH3_128bits(const void* input, size_t len)
{
    return XXH3_128bits_internal(input, len, 0,
                                 XXH3_kSecret, sizeof(XXH3_kSecret),
                                 XXH3_hashLong_128b_default);
}


XXH_PUBLIC_API XXH128_hash_t
XXH3_128bits_withSecret(const void* input, size_t len, const void* secret, size_t secretSize)
{
    return XXH3_128bits_internal(input, len, 0,
                                 (const xxh_u8*)secret, secretSize,
                                 XXH3_hashLong_128b_withSecret);
}


XXH_PUBLIC_API XXH128_hash_t
XXH3_128bits_withSeed(const void* input, size_t len, XXH64_hash_t seed)
{
    return XXH3_128bits_internal(input, len, seed,
                                 XXH3_kSecret, sizeof(XXH3_kSecret),
                                 XXH3_hashLong_128b_withSeed);
}


XXH_PUBLIC_API XXH128_hash_t
XXH3_128bits_withSecretandSeed(const void* input, size_t len, const void* secret, size_t secretSize, XXH64_hash_t seed)
{
    if (len <= XXH3_MIDSIZE_MAX)
        return XXH3_128bits_internal(input, len, seed, XXH3_kSecret, sizeof(XXH3_kSecret), NULL);
    return XXH3_hashLong_128b_withSecret(input, len, seed, secret, secretSize);
}


XXH_PUBLIC_API XXH128_hash_t
XXH128(const void* input, size_t len, XXH64_hash_t seed)
{
    return XXH3_128bits_withSeed(input, len, seed);
}



#ifndef XXH_NO_STREAM



XXH_PUBLIC_API XXH_errorcode
XXH3_128bits_reset(XXH3_state_t* statePtr)
{
    return XXH3_64bits_reset(statePtr);
}


XXH_PUBLIC_API XXH_errorcode
XXH3_128bits_reset_withSecret(XXH3_state_t* statePtr, const void* secret, size_t secretSize)
{
    return XXH3_64bits_reset_withSecret(statePtr, secret, secretSize);
}


XXH_PUBLIC_API XXH_errorcode
XXH3_128bits_reset_withSeed(XXH3_state_t* statePtr, XXH64_hash_t seed)
{
    return XXH3_64bits_reset_withSeed(statePtr, seed);
}


XXH_PUBLIC_API XXH_errorcode
XXH3_128bits_reset_withSecretandSeed(XXH3_state_t* statePtr, const void* secret, size_t secretSize, XXH64_hash_t seed)
{
    return XXH3_64bits_reset_withSecretandSeed(statePtr, secret, secretSize, seed);
}


XXH_PUBLIC_API XXH_errorcode
XXH3_128bits_update(XXH3_state_t* state, const void* input, size_t len)
{
    return XXH3_update(state, (const xxh_u8*)input, len,
                       XXH3_accumulate, XXH3_scrambleAcc);
}


XXH_PUBLIC_API XXH128_hash_t XXH3_128bits_digest (const XXH3_state_t* state)
{
    const unsigned char* const secret = (state->extSecret == NULL) ? state->customSecret : state->extSecret;
    if (state->totalLen > XXH3_MIDSIZE_MAX) {
        XXH_ALIGN(XXH_ACC_ALIGN) XXH64_hash_t acc[XXH_ACC_NB];
        XXH3_digest_long(acc, state, secret);
        XXH_ASSERT(state->secretLimit + XXH_STRIPE_LEN >= sizeof(acc) + XXH_SECRET_MERGEACCS_START);
        {   XXH128_hash_t h128;
            h128.low64  = XXH3_mergeAccs(acc,
                                         secret + XXH_SECRET_MERGEACCS_START,
                                         (xxh_u64)state->totalLen * XXH_PRIME64_1);
            h128.high64 = XXH3_mergeAccs(acc,
                                         secret + state->secretLimit + XXH_STRIPE_LEN
                                                - sizeof(acc) - XXH_SECRET_MERGEACCS_START,
                                         ~((xxh_u64)state->totalLen * XXH_PRIME64_2));
            return h128;
        }
    }
    
    if (state->seed)
        return XXH3_128bits_withSeed(state->buffer, (size_t)state->totalLen, state->seed);
    return XXH3_128bits_withSecret(state->buffer, (size_t)(state->totalLen),
                                   secret, state->secretLimit + XXH_STRIPE_LEN);
}
#endif 


#include <string.h>   



XXH_PUBLIC_API int XXH128_isEqual(XXH128_hash_t h1, XXH128_hash_t h2)
{
    
    return !(memcmp(&h1, &h2, sizeof(h1)));
}



XXH_PUBLIC_API int XXH128_cmp(const void* h128_1, const void* h128_2)
{
    XXH128_hash_t const h1 = *(const XXH128_hash_t*)h128_1;
    XXH128_hash_t const h2 = *(const XXH128_hash_t*)h128_2;
    int const hcmp = (h1.high64 > h2.high64) - (h2.high64 > h1.high64);
    
    if (hcmp) return hcmp;
    return (h1.low64 > h2.low64) - (h2.low64 > h1.low64);
}




XXH_PUBLIC_API void
XXH128_canonicalFromHash(XXH128_canonical_t* dst, XXH128_hash_t hash)
{
    XXH_STATIC_ASSERT(sizeof(XXH128_canonical_t) == sizeof(XXH128_hash_t));
    if (XXH_CPU_LITTLE_ENDIAN) {
        hash.high64 = XXH_swap64(hash.high64);
        hash.low64  = XXH_swap64(hash.low64);
    }
    XXH_memcpy(dst, &hash.high64, sizeof(hash.high64));
    XXH_memcpy((char*)dst + sizeof(hash.high64), &hash.low64, sizeof(hash.low64));
}


XXH_PUBLIC_API XXH128_hash_t
XXH128_hashFromCanonical(const XXH128_canonical_t* src)
{
    XXH128_hash_t h;
    h.high64 = XXH_readBE64(src);
    h.low64  = XXH_readBE64(src->digest + 8);
    return h;
}




#define XXH_MIN(x, y) (((x) > (y)) ? (y) : (x))

XXH_FORCE_INLINE void XXH3_combine16(void* dst, XXH128_hash_t h128)
{
    XXH_writeLE64( dst, XXH_readLE64(dst) ^ h128.low64 );
    XXH_writeLE64( (char*)dst+8, XXH_readLE64((char*)dst+8) ^ h128.high64 );
}


XXH_PUBLIC_API XXH_errorcode
XXH3_generateSecret(void* secretBuffer, size_t secretSize, const void* customSeed, size_t customSeedSize)
{
#if (XXH_DEBUGLEVEL >= 1)
    XXH_ASSERT(secretBuffer != NULL);
    XXH_ASSERT(secretSize >= XXH3_SECRET_SIZE_MIN);
#else
    
    if (secretBuffer == NULL) return XXH_ERROR;
    if (secretSize < XXH3_SECRET_SIZE_MIN) return XXH_ERROR;
#endif

    if (customSeedSize == 0) {
        customSeed = XXH3_kSecret;
        customSeedSize = XXH_SECRET_DEFAULT_SIZE;
    }
#if (XXH_DEBUGLEVEL >= 1)
    XXH_ASSERT(customSeed != NULL);
#else
    if (customSeed == NULL) return XXH_ERROR;
#endif

    
    {   size_t pos = 0;
        while (pos < secretSize) {
            size_t const toCopy = XXH_MIN((secretSize - pos), customSeedSize);
            memcpy((char*)secretBuffer + pos, customSeed, toCopy);
            pos += toCopy;
    }   }

    {   size_t const nbSeg16 = secretSize / 16;
        size_t n;
        XXH128_canonical_t scrambler;
        XXH128_canonicalFromHash(&scrambler, XXH128(customSeed, customSeedSize, 0));
        for (n=0; n<nbSeg16; n++) {
            XXH128_hash_t const h128 = XXH128(&scrambler, sizeof(scrambler), n);
            XXH3_combine16((char*)secretBuffer + n*16, h128);
        }
        
        XXH3_combine16((char*)secretBuffer + secretSize - 16, XXH128_hashFromCanonical(&scrambler));
    }
    return XXH_OK;
}


XXH_PUBLIC_API void
XXH3_generateSecret_fromSeed(void* secretBuffer, XXH64_hash_t seed)
{
    XXH_ALIGN(XXH_SEC_ALIGN) xxh_u8 secret[XXH_SECRET_DEFAULT_SIZE];
    XXH3_initCustomSecret(secret, seed);
    XXH_ASSERT(secretBuffer != NULL);
    memcpy(secretBuffer, secret, XXH_SECRET_DEFAULT_SIZE);
}




#if XXH_VECTOR == XXH_AVX2  \
  && defined(__GNUC__) && !defined(__clang__)  \
  && defined(__OPTIMIZE__) && XXH_SIZE_OPT <= 0 
#  pragma GCC pop_options
#endif

#endif  

#endif


#endif


#if defined (__cplusplus)
}
#endif
