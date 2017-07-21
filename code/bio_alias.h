//
// Created by Fábio Domingues on 20/07/17.
//

#ifndef CRASHMONKEY_BIO_ALIAS_H
#define CRASHMONKEY_BIO_ALIAS_H

#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 13, 0) \
  && LINUX_VERSION_CODE < KERNEL_VERSION(3, 14, 0)

#define BI_SIZE                 bi_size
#define BI_SECTOR               bi_sector
#define BIO_ENDIO(bio, err)     bio_endio(bio, err)

#elif LINUX_VERSION_CODE >= KERNEL_VERSION(4, 4, 0) \
  && LINUX_VERSION_CODE < KERNEL_VERSION(4, 5, 0)

#define BI_SIZE                 bi_iter.bi_size
#define BI_SECTOR               bi_iter.bi_sector
#define BIO_ENDIO(bio, err)     bio->bi_error = err; bio_endio(bio)

#else
#error "Unsupported kernel version: crashmonkey has not been tested with your kernel version."
#endif

#endif //CRASHMONKEY_BIO_ALIAS_H
