enum device_variant {
    J710FN,
    J710MN,
    J710K,
    J710GN,
    J710F,
};

device_variant match(std::string bl)
{
    if (bl.find("J710FN") != std::string::npos) {
        return J710FN;
    } else if (bl.find("J710MN") != std::string::npos) {
        return J710MN;
    } else if (bl.find("J710K") != std::string::npos) {
        return J710K;
    } else if (bl.find("J710GN") != std::string::npos) {
        return J710GN;
    } else {
        return J710F;
    }
}
