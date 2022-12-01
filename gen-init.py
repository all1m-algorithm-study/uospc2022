import os
import shutil

def gen_init(tc_files):
    lines = ["test_cases:"]
    in_files = [None for _ in range(len(tc_files) // 2)]
    out_files = [None for _ in range(len(tc_files) // 2)]
    for tc_file in tc_files:
        tc_name = None; is_out = None
        if '.' in tc_file:
            tc_name = tc_file.split('.')[0]
            is_out = True
        else:
            tc_name = tc_file
            is_out = False;
        index = int(tc_name)-1
        if is_out:
            out_files[index] = tc_file
        else:
            in_files[index] = tc_file
    for i in range(len(in_files)):
        points = 0 if (i < len(in_files)-1) else 100
        lines.append(f" - {{in: {in_files[i]}, out: {out_files[i]}, points: {points}}}")
    return "\n".join(lines)

if __name__ == "__main__":
    prob_dirs = next(os.walk("problems"))[1]
    for prob in prob_dirs:
        print(prob)

        try:
            prob_path = os.path.join("problems", prob)
            pars_path = os.path.join(".testcases", prob.replace("_", "").replace("-", "").lower())
            os.makedirs(pars_path, exist_ok=True)

            tc_root = os.path.join(prob_path, "tests")
            tc_files = []
            for tc_file in os.listdir(tc_root):
                tc_src = os.path.join(tc_root, tc_file)
                tc_dst = os.path.join(pars_path, tc_file)
                if os.path.isdir(tc_src):
                    continue
                shutil.copyfile(tc_src, tc_dst)
                tc_files.append(tc_file)
            
            with open(os.path.join(pars_path, "init.yml"), "w") as init_file:
                init_file.write(gen_init(tc_files))
        except:
            print(f"({prob} is passed.)")