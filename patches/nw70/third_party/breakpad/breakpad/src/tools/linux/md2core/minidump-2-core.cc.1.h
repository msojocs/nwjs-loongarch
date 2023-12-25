  unsigned char  pr_zomb;       /* Zombie                                    */
  signed char    pr_nice;       /* Nice val                                  */
  unsigned long  pr_flag;       /* Flags                                     */
#if defined(__x86_64__) || defined(__mips__)
  uint32_t       pr_uid;        /* User ID                                   */
  uint32_t       pr_gid;        /* Group ID                                  */
#else

//----replace
  unsigned char  pr_zomb;       /* Zombie                                    */
  signed char    pr_nice;       /* Nice val                                  */
  unsigned long  pr_flag;       /* Flags                                     */
#if defined(__x86_64__) || defined(__mips__) || defined(__loongarch64)
  uint32_t       pr_uid;        /* User ID                                   */
  uint32_t       pr_gid;        /* Group ID                                  */
#else
