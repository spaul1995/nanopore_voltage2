    if (runTime.writeTime())
    {
        volVectorField gradV(fvc::grad(V));

        volScalarField gradVx
        (
            IOobject
            (
                "gradVx",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            gradV.component(vector::X)
        );

        volScalarField gradVy
        (
            IOobject
            (
                "gradVy",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            gradV.component(vector::Y)
        );

        volScalarField gradVz
        (
            IOobject
            (
                "gradVz",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            gradV.component(vector::Z)
        );


        runTime.write();
    }
