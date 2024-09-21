import os
import re
import sys

# takes in a path to the PDB file and a path to the IDA-ready PDB file

# What we do here is we call llvm-pdbutil to dump the PDB file into a YAML file.
# We then take the PDB file in as one line, Search and replace all the `\bRE::` with "" and then
# search and replace all the mangled RE namespace names (i.e. "@RE@@") with "@@".
# Then we output it to another yaml and then call llvm-pdbutil again to convert it back to a PDB file.

# llvm-pdbutil is in the path if vcvarsall.bat is run (and clang is installed)
# otherwise, you can set the path to llvm-pdbutil.exe in the environment variable PDBUTIL_PATH
# i.e. set PDBUTIL_PATH=C:\Program Files\LLVM\bin\llvm-pdbutil.exe
PDBUTIL_PATH = os.environ.get("PDBUTIL_PATH", "llvm-pdbutil.exe")

# NOTE: this can fail if the executing shell is UTF-16 (i.e. old PowerShell)
# Python uses cmd.exe by default, so it should be fine
def convert_pdb_to_yaml(pdb_file, yaml_file):
   print("using " + PDBUTIL_PATH)
   if os.system(PDBUTIL_PATH + " pdb2yaml --all %s > %s" % (pdb_file, yaml_file)):
            raise Exception("Failed to convert pdb to yaml")
    
def convert_yaml_to_pdb(yaml_file, pdb_file):
   if os.system(PDBUTIL_PATH + ' yaml2pdb --pdb="%s" %s ' % (pdb_file, yaml_file)):
         raise Exception("Failed to convert yaml to pdb")
    
def manip(pdb_file, new_pdb_file):
    # get the dir of the pdb file
    pdb_dir = os.path.dirname(pdb_file)
    yaml_file = os.path.join(pdb_dir, "temp.yaml")
    convert_pdb_to_yaml(pdb_file, yaml_file)
    with open(yaml_file, "r") as f:
        data = f.read()
        data = re.sub(r"\bRE::DirectInput8::", "", data)
        data = re.sub(r"\bRE::DirectX::", "", data)
        data = re.sub(r"\bREX::W32::", "", data)
        data = re.sub(r"\bSFSE::stl::", "stl::", data)
        data = re.sub(r"\bRE::", "", data)
        # get the mangled names too
        data = re.sub("@DirectInput8@RE@@", "@@", data)
        data = re.sub("@DirectX@RE@@", "@@", data)
        data = re.sub("@W32@REX@@", "@@", data)
        data = re.sub("@stl@SFSE@@", "@stl@@", data)
        data = re.sub("@RE@@", "@@", data)
    with open(yaml_file, "w") as f:
        f.write(data)
    convert_yaml_to_pdb(yaml_file, new_pdb_file)
    #remove the temp
    # os.remove(yaml_file)
    
def main(argc, argv):
    manip(argv[1], argv[2])
    
if __name__ == "__main__":
    # pass in argc, argv
    main(len(sys.argv), sys.argv)