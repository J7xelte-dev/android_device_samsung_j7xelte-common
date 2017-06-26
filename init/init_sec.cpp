#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "property_service.h"
#include "util.h"
#include "vendor_init.h"

#include "init_sec.h"

std::string bootloader;
std::string device;
char* devicename;

device_variant check_device_and_get_variant()
{
    bootloader = property_get("ro.bootloader");
    return match(bootloader);
}

void vendor_load_properties()
{
    device_variant variant = check_device_and_get_variant();

    switch (variant) {
        case J710FN:
            /* j7xeltexx */
            property_set("ro.build.fingerprint", "samsung/j7xeltexx/j7xelte:6.0.1/MMB29K/J710FXXU3AQD4:user/release-keys");
            property_set("ro.build.description", "j7xeltexx-user 6.0.1 MMB29K J710FXXU3AQD4 release-keys");
            property_set("ro.product.model", "SM-J710FN");
            property_set("ro.product.device", "j7xeltexx");
            break;
        case J710MN:
            /* j7xelteub */
            property_set("ro.build.fingerprint", "samsung/j7xelteub/j7xelte:6.0.1/MMB29K/J710FXXU3AQD4:user/release-keys");
            property_set("ro.build.description", "j7xelteub-user 6.0.1 MMB29K J710FXXU3AQD4 release-keys");
            property_set("ro.product.model", "SM-J710MN");
            property_set("ro.product.device", "j7xelteub");
            break;
        case J710K:
            /* j7xeltektt */
            property_set("ro.build.fingerprint", "samsung/j7xeltektt/j7xelte:6.0.1/MMB29K/J710FXXU3AQD4:user/release-keys");
            property_set("ro.build.description", "j7xeltektt-user 6.0.1 MMB29K J710FXXU3AQD4 release-keys");
            property_set("ro.product.model", "SM-J710K");
            property_set("ro.product.device", "j7xeltektt");
            break;
        case J710GN:
            /* j7xeltedx */
            property_set("ro.build.fingerprint", "samsung/j7xeltedx/j7xelte:6.0.1/MMB29K/J710FXXU3AQD4:user/release-keys");
            property_set("ro.build.description", "j7xeltedx-user 6.0.1 MMB29K J710FXXU3AQD4 release-keys");
            property_set("ro.product.model", "SM-J710GN");
            property_set("ro.product.device", "j7xeltedx");
            break;
        default: /* J710F */
            /* j7xeltexx */
            property_set("ro.build.fingerprint", "samsung/j7xeltexx/j7xelte:6.0.1/MMB29K/J710FXXU3AQD4:user/release-keys");
            property_set("ro.build.description", "j7xeltexx-user 6.0.1 MMB29K J710FXXU3AQD4 release-keys");
            property_set("ro.product.model", "SM-J710F");
            property_set("ro.product.device", "j7xeltexx");
            break;
    }

    device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
