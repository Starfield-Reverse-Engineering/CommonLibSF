from json import dumps, load
from re import sub
from subprocess import run

vcpkg_repo = "https://github.com/microsoft/vcpkg"
custom_vcpkg_registry_repo = "https://github.com/ThirdEyeSqueegee/vcpkg-ports"

vcpkg_ref = (
    run(["git", "ls-remote", vcpkg_repo, "refs/heads/master"], capture_output=True)
    .stdout.decode()
    .splitlines()[0]
    .split()[0]
)

custom_vcpkg_registry_ref = (
    run(["git", "ls-remote", custom_vcpkg_registry_repo], capture_output=True)
    .stdout.decode()
    .splitlines()[0]
    .split()[0]
)

with open("./vcpkg.json") as f:
    vcpkg_json = load(f)

vcpkg_json["builtin-baseline"] = vcpkg_ref
vcpkg_json["vcpkg-configuration"]["registries"][0]["baseline"] = (
    custom_vcpkg_registry_ref
)

vcpkg_json_str = dumps(vcpkg_json, indent=2)
vcpkg_json_str += "\n"

with open("./vcpkg.json", "w", newline="\r\n") as f:
    f.write(vcpkg_json_str)

with open("./.github/workflows/main_ci.yml") as f:
    main_ci_yml = f.read()

main_ci_yml = sub(
    r"(VCPKG_COMMIT_ID: ).*", f"VCPKG_COMMIT_ID: {vcpkg_ref}", main_ci_yml
)

with open("./.github/workflows/main_ci.yml", "w") as f:
    f.write(main_ci_yml)
