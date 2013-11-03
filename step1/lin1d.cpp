#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <mgl2/mgl.h>

using namespace std;

int main()
{

    double nx = 41; // Number of points
    double dx = 2/(nx-1); // Distance between points
    double nt = 25; // Number of timesteps
    double dt = .025; // Timestep difference
    double c = 1; // Wavespeed

    Eigen::VectorXd u(nx); // Contructs new eigen vector object called u, of size nx
    u.setOnes(nx); // Set to ones

    for (double i=.5/dx;i<(1/dx)+1;i++) // Set the elements between .05 and 1 as u=2
    {
        u[i] = 2;
    }

    Eigen::VectorXd x; // A vector to hold our x values
    x.setLinSpaced(nx,0,2);


    ofstream writefile("data-before.dat", ios::out | ios::trunc);

    for (int j=0;j<nx;j++)
    {
        writefile << x[j] << "\t" << u[j] << endl;
    }
    writefile.close();

    Eigen::VectorXd un(nx); // Placeholder vector for temporary storage of values

    for (int j=0;j<nt;j++)
    {
        un << u; // Copy the contents of u into un

        for (int k=1;k<nx;k++)
        {
            u[k] = un[k]-c*dt/dx*(un[k]-un[k-1]);
        }
    }

    un.resize(0); // Frees the memory

    ofstream writefile2("data-after.dat", ios::out | ios::trunc);

    for (int k=0;k<nx;k++)
    {
        writefile2 << x[k] << "\t" << u[k] << endl;
    }
    writefile2.close();

    u.resize(0); // Free the memory

    mglGraph gr; // Start mgl graph object that holds all graph stuff

    mglData y("data-before.dat"); // Load one set of data
    mglData z("data-after.dat"); // Load the other, I really better stick both of these in a single file... along with all the other steps.

    gr.SetOrigin(0,0,0);
    gr.Title("Plot");
    gr.Box(); // Not sure what this does...
    gr.Plot(y); // Puts the data into the graph
    gr.Plot(z); // Same as previous line
    gr.WritePNG("test.png"); // Write out to PNG file

    return 0;

}