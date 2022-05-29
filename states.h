struct arm_saved_state32 {
	uint32_t r[13];     /* General purpose register r0-r12 */
	uint32_t sp;        /* Stack pointer r13 */
	uint32_t lr;        /* Link register r14 */
	uint32_t pc;        /* Program counter r15 */
	uint32_t cpsr;      /* Current program status register */
	uint32_t far;       /* Virtual fault address */
	uint32_t esr;       /* Exception syndrome register */
	uint32_t exception; /* Exception number */
};
typedef struct arm_saved_state32 arm_saved_state32_t;

struct arm_saved_state32_tagged {
	uint32_t                 tag;
	struct arm_saved_state32 state;
};
typedef struct arm_saved_state32_tagged arm_saved_state32_tagged_t;

#define ARM_SAVED_STATE32_COUNT ((mach_msg_type_number_t) \
	        (sizeof(arm_saved_state32_t)/sizeof(unsigned int)))

struct arm_saved_state64 {
	uint64_t x[29];     /* General purpose registers x0-x28 */
	uint64_t fp;        /* Frame pointer x29 */
	uint64_t lr;        /* Link register x30 */
	uint64_t sp;        /* Stack pointer x31 */
	uint64_t pc;        /* Program counter */
	uint32_t cpsr;      /* Current program status register */
	uint32_t reserved;  /* Reserved padding */
	uint64_t far;       /* Virtual fault address */
	uint32_t esr;       /* Exception syndrome register */
	uint32_t exception; /* Exception number */
#if defined(HAS_APPLE_PAC)
	uint64_t jophash;
#endif /* defined(HAS_APPLE_PAC) */
};
typedef struct arm_saved_state64 arm_saved_state64_t;

#define ARM_SAVED_STATE64_COUNT ((mach_msg_type_number_t) \
	(sizeof(arm_saved_state64_t)/sizeof(unsigned int)))

struct arm_saved_state64_tagged {
	uint32_t                 tag;
	struct arm_saved_state64 state;
};
typedef struct arm_saved_state64_tagged arm_saved_state64_tagged_t;

struct arm_saved_state {
	arm_state_hdr_t ash;
	union {
		struct arm_saved_state32 ss_32;
		struct arm_saved_state64 ss_64;
	} uss;
} __attribute__((aligned(16)));
#define ss_32 uss.ss_32
#define ss_64 uss.ss_64

typedef struct arm_saved_state arm_saved_state_t;