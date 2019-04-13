import sys
import os
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="To be scanned folder")

    args = parser.parse_args()
    if args.input is None:
        print(parser.print_help())
        return

    count = 0
    for dir_path, dir_names, file_names in os.walk(args.input):
        for file_name in file_names:
            if not file_name.endswith(".cpp"):
                continue
            count += 1        

    print("Current Mileage: %s" % count)


if __name__ == "__main__":
    main()
