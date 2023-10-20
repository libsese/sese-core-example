set(SOURCE_PATH ${CURRENT_BUILDTRESS_DIR}/sese)

vcpkg_from_git(
        OUT_SOURCE_PATH SOURCE_PATH
        URL https://github.com/libsese/sese-core
        REF 346b1c679cb64a54b56a1543efcc51ccc492a1ab
        HEAD_REF HEAD
)

vcpkg_check_features(OUT_FEATURE_OPTIONS FEATURE_OPTIONS
        FEATURES
        tests        SESE_BUILD_TEST
        async-logger USE_ASYNC_LOGGER
)

vcpkg_cmake_configure(
        SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()

vcpkg_fixup_cmake_targets(CONFIG_PATH lib/cmake/sese)

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

file(COPY "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/sese")
file(RENAME "${CURRENT_PACKAGES_DIR}/share/sese/LICENSE" "${CURRENT_PACKAGES_DIR}/share/sese/copyright")