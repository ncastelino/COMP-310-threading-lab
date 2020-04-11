#!/usr/local/bin/python3



def print_points(pts):
    
    for k in range(len(pts)):
        print(str(pts[k]) + ", ", end =" ")
        if (k+1) % 8 == 0: # Print newline after 8 points
            print()

def main():
    cube_pts = [0., 0., 0., 1., 0., 0., 1., 1., 0., 0., 1., 0., 0., 0., 1., 0., 1., 1., 1., 1., 1., 0., 1., 1.];

    print("double points[] = {")

    for offset in range(1,3000000,3):

        print_points([x + float(offset) for x in cube_pts])

    print("};")
    print("unsigned int points_len = sizeof(points) / sizeof(points[0]);")

if __name__ == "__main__":
    main()
