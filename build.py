#!/usr/bin/env python
# -*- coding: utf-8 -*-

from itertools import product

from bincrafters import build_template_default

settings = {
    "arch": ["x86", "x86_64"],
    "build_type": ["Debug", "Release"],
    "compiler": ["clang", "gcc"],
}
compiler_settings = {
    "clang": {"version": ["8"], "libcxx": ["libstdc++11"], "cppstd": ["17"]}
}
options = {"enable_double_precision": [True, False], "shared": [True, False]}


def generate_combinations(options):
    items = sorted(options.items(), key=lambda x: x[0])
    keys = [item[0] for item in items]
    values = [item[1] for item in items]
    for value in product(*values):
        yield {key: v for key, v in zip(keys, value)}


if __name__ == "__main__":

    builder = build_template_default.get_builder()
    for setting in generate_combinations(settings):
        if setting["compiler"] in compiler_settings:
            for compiler_setting in generate_combinations(compiler_settings):
                settings.update()
                for option in generate_combinations(options):
                    builder.add(
                        settings=setting, options=option, env_vars={}, build_requires={}
                    )

    builder.run()
