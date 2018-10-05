Info<< "Reading field V\n" << endl;

volScalarField V
(
    IOobject
    (
        "V",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field Temp\n" << endl;

volScalarField Temp
(
    IOobject
    (
        "Temp",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
/*
    volVectorField E
    (
        IOobject
        (
            "E",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );
*/
volScalarField rho_c
(
    IOobject
    (
        "rho_c",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);


Info<< "Reading diffusivity DT\n" << endl;

dimensionedScalar DT
(
    transportProperties.lookup("DT")
);

Info<< "Reading diffusivity sigma1\n" << endl;

dimensionedScalar sigma1
(
    transportProperties.lookup("sigma1")
);

Info<< "Reading diffusivity sigma2\n" << endl;

dimensionedScalar sigma2
(
    transportProperties.lookup("sigma2")
);

Info<< "Reading diffusivity sigma3\n" << endl;

dimensionedScalar sigma3
(
    transportProperties.lookup("sigma3")
);

Info<< "Reading diffusivity sigma4\n" << endl;

dimensionedScalar sigma4
(
    transportProperties.lookup("sigma4")
);

Info<< "Reading diffusivity epsilon1\n" << endl;

dimensionedScalar epsilon1
(
    transportProperties.lookup("epsilon1")
);

Info<< "Reading diffusivity epsilon2\n" << endl;

dimensionedScalar epsilon2
(
    transportProperties.lookup("epsilon2")
);

Info<< "Reading diffusivity epsilon3\n" << endl;

dimensionedScalar epsilon3
(
    transportProperties.lookup("epsilon3")
);

Info<< "Reading diffusivity epsilon4\n" << endl;

dimensionedScalar epsilon4
(
    transportProperties.lookup("epsilon4")
);

volScalarField sigma
(
    IOobject
    (
        "sigma",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    sigma1*pow(Temp,3)+sigma2*pow(Temp,2)+sigma3*pow(Temp,1)+sigma4
);

volScalarField epsilon
(
    IOobject
    (
        "epsilon",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    epsilon1*epsilon2*exp(epsilon3*(Temp-epsilon4))
);
