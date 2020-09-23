//::|сссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сс|						~ A R I E L   P R O D U C T I O N S ~                     |сс|::
//::|сс|                               ~ ALL RIGHTS RESERVED ~                            |сс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сс| ~ PROGRAM DATA ~													      /-----/ |сс|::
//::|сс|							            								/-----/ | |сс|::
//::|сс| PROGRAMMER:: James Dougherty											| |   | | |сс|::
//::|сс| COPYRIGHT :: ©2002-2003 Ariel Productions								| |   | | |сс|::
//::|сс| TYPE      :: Game Engine												| /---|-/ |сс|::
//::|сс|																		/-----/   |сс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сс| ~ SOURCE DATA ~																  |сс|::
//::|сс|																				  |сс|::
//::|сс| FILENAME	   :: XVector3.cpp													  |сс|::
//::|сс| VERSION	   :: 1.0															  |сс|::
//::|сс| REVISION DATE :: 00.00.00														  |сс|::
//::|сс|																				  |сс|::
//::|сс| REVISION DATA ::																  |сс|::
//::|сс| | 																				  |сс|::
//::|сс| |-00.00.00																		  |сс|::
//::|сс| |-																				  |сс|::
//::|сс| |-N/A																			  |сс|::
//::|сс| |																				  |сс|::
//::|сс|																				  |сс|::
//::|сс| BUGS ::																		  |сс|::
//::|сс| |																				  |сс|::
//::|сс| |-N/A																			  |сс|::
//::|сс| |																				  |сс|::
//::|сс|																				  |сс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссс|::

#include "XVector3.h"

//|тфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфу|
//|тфу								 Vector 3									    тфу|
//|тфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфутфу|

XVECTOR3::XVECTOR3() : X(0), Y(0), Z(0)
{
	//--
}

//========================================================================

XVECTOR3::XVECTOR3(const XVECTOR3 &Vector)
{
	this->X = Vector.X;
	this->Y = Vector.Y;
	this->Z = Vector.Z;
}

//========================================================================

XVECTOR3::XVECTOR3(const Xfloat Value)
{
	this->X = this->Y = this->Z = Value;
}

//========================================================================

XVECTOR3::XVECTOR3(const Xfloat *Value)
{
	this->X = Value[0];
	this->Y = Value[1];
	this->Z = Value[2];
}

//========================================================================

XVECTOR3::XVECTOR3(Xfloat X, Xfloat Y, Xfloat Z)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

//========================================================================

XVECTOR3::operator Xfloat* ()
{
	return (Xfloat *) &X;
}

//========================================================================

XVECTOR3::operator const Xfloat* () const
{
	return (const Xfloat *) &X;
}

//========================================================================

XVECTOR3 XVECTOR3::operator * (Xfloat Scalar) const
{
	return XVECTOR3(this->X * Scalar, this->Y * Scalar, this->Z * Scalar);
}

//========================================================================

XVECTOR3 XVECTOR3::operator * (const XVECTOR3 &Vector) const
{
	return XVECTOR3(this->X * Vector.X, this->Y * Vector.Y, this->Z * Vector.Z);
}

//========================================================================

XVECTOR3 XVECTOR3::operator / (Xfloat Scalar) const
{
	return XVECTOR3(this->X / Scalar, this->Y / Scalar, this->Z / Scalar);
}

//========================================================================

XVECTOR3 XVECTOR3::operator / (const XVECTOR3 &Vector) const
{
	return XVECTOR3(this->X / Vector.X, this->Y / Vector.Y, this->Z / Vector.Z);
}

//========================================================================

XVECTOR3 XVECTOR3::operator < (const XVECTOR3 &Vector) const
{
	XVECTOR3 Minimized;
	Minimized.X = this->X < Vector.X ? this->X : Vector.X;
    Minimized.Y = this->Y < Vector.Y ? this->Y : Vector.Y;
	Minimized.Z = this->Z < Vector.Z ? this->Z : Vector.Z;
	return Minimized;
}

//========================================================================

XVECTOR3 XVECTOR3::operator > (const XVECTOR3 &Vector) const
{
	XVECTOR3 Maximized;
	Maximized.X = this->X > Vector.X ? this->X : Vector.X;
    Maximized.Y = this->Y > Vector.Y ? this->Y : Vector.Y;
	Maximized.Z = this->Z > Vector.Z ? this->Z : Vector.Z;
	return Maximized;
}

//========================================================================

XVECTOR3 XVECTOR3::operator^(XVECTOR3 const &Vector) const
{
	return XVECTOR3((this->Y * Vector.Z - this->Z * Vector.Y),
					(this->Z * Vector.X - this->X * Vector.Z),
					(this->X * Vector.Y - this->Y * Vector.X));
}

//========================================================================

XVECTOR3 XVECTOR3::operator + (const XVECTOR3 &Vector) const
{
	return XVECTOR3(this->X + Vector.X, this->Y + Vector.Y, this->Z + Vector.Z);
}

//========================================================================

XVECTOR3 XVECTOR3::operator - (const XVECTOR3 &Vector) const
{
	return XVECTOR3(this->X - Vector.X, this->Y - Vector.Y, this->Z - Vector.Z);
}

//========================================================================

Xbool XVECTOR3::operator == (const XVECTOR3 &Vector) const
{
	if(XMATH::FFabs(this->X - Vector.X) < XMATH::EPSILON)
	{
		if(XMATH::FFabs(this->Y - Vector.Y) < XMATH::EPSILON)
		{
			if(XMATH::FFabs(this->Z - Vector.Z) < XMATH::EPSILON)
			{
				return Xtrue;
			}
		}
	}
	return Xfalse;
}

//========================================================================

Xbool XVECTOR3::operator != (const XVECTOR3 &Vector) const
{
	if(XMATH::FFabs(this->X - Vector.X) > XMATH::EPSILON)
	{
		if(XMATH::FFabs(this->Y - Vector.Y) > XMATH::EPSILON)
		{
			if(XMATH::FFabs(this->Z - Vector.Z) > XMATH::EPSILON)
			{
				return Xtrue;
			}
		}
	}
	return Xfalse;
}

//========================================================================

Xfloat XVECTOR3::operator % (const XVECTOR3 &Vector) const
{
	return ((this->X * Vector.X) + (this->Y * Vector.Y) + (this->Z * Vector.Z));
}

//========================================================================

XVECTOR3& XVECTOR3::operator += (const XVECTOR3 &Vector)
{
	this->X += Vector.X;
	this->Y += Vector.Y;
	this->Z += Vector.Z;
	return *this;
}

//========================================================================

XVECTOR3& XVECTOR3::operator -= (const XVECTOR3 &Vector)
{
	this->X -= Vector.X;
	this->Y -= Vector.Y;
	this->Z -= Vector.Z;
	return *this;
}

//========================================================================

XVECTOR3& XVECTOR3::operator *= (Xfloat Scalar)
{
	this->X *= Scalar;
	this->Y *= Scalar;
	this->Z *= Scalar;
	return *this;
}

//========================================================================

XVECTOR3& XVECTOR3::operator /= (Xfloat Scalar)
{
	this->X /= Scalar;
	this->Y /= Scalar;
	this->Z /= Scalar;
	return *this;
}

//========================================================================

XVECTOR3 XVECTOR3::operator + () const
{
	return *this;
}

//========================================================================

XVECTOR3 XVECTOR3::operator - () const
{
	return XVECTOR3(-this->X, -this->Y, -this->Z);
}

//========================================================================

XVECTOR3 XVECTOR3::Add(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	return XVECTOR3(Vector1->X + Vector2->X, Vector1->Y + Vector2->Y, Vector1->Z + Vector2->Z);
}

//========================================================================

XVECTOR3 XVECTOR3::Subtract(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	return XVECTOR3(Vector1->X - Vector2->X, Vector1->Y - Vector2->Y, Vector1->Z - Vector2->Z);
}

//========================================================================

XVECTOR3 XVECTOR3::Average(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	XVECTOR3 Sum; Sum.Add(Vector1, Vector2);
	return XVECTOR3(Sum.X /= 4, Sum.Y /= 4, Sum.Z /= 4);
}

//========================================================================

XVECTOR3 XVECTOR3::Divide(Xfloat Scalar, const XVECTOR3 *Vector)
{
	return XVECTOR3(Vector->X / Scalar, Vector->Y / Scalar, Vector->Z / Scalar);
}

//========================================================================

XVECTOR3 XVECTOR3::Divide(const XVECTOR3 *Vector, Xfloat Scalar)
{
	return XVECTOR3(Vector->X / Scalar, Vector->Y / Scalar, Vector->Z / Scalar);
}

//========================================================================

XVECTOR3 XVECTOR3::Divide(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	return XVECTOR3(Vector1->X / Vector2->X, Vector1->Y / Vector2->Y, Vector1->Z / Vector2->Z);
}

//========================================================================

XVECTOR3 XVECTOR3::Multiply(Xfloat Scalar, const XVECTOR3 *Vector)
{
	return XVECTOR3(Vector->X * Scalar, Vector->Y * Scalar, Vector->Z * Scalar);
}

//========================================================================

XVECTOR3 XVECTOR3::Multiply(const XVECTOR3 *Vector, Xfloat Scalar)
{
	return XVECTOR3(Vector->X * Scalar, Vector->Y * Scalar, Vector->Z * Scalar);
}

//========================================================================

XVECTOR3 XVECTOR3::Multiply(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	return XVECTOR3(Vector1->X * Vector2->X, Vector1->Y * Vector2->Y, Vector1->Z * Vector2->Z);
}

//========================================================================

Xfloat XVECTOR3::DotProduct(const XVECTOR3 *Vector)
{
	return ((this->X * Vector->X) + (this->Y * Vector->Y) + (this->Z * Vector->Z));
}

//========================================================================

Xvoid XVECTOR3::Copy(XVECTOR3 *Vector)
{
	this->X = Vector->X;
	this->Y = Vector->Y;
	this->Z = Vector->Z;
}

//========================================================================

Xvoid XVECTOR3::Zero(Xvoid)
{
	this->X = this->Y = this->Z = 0.0f;
}

//========================================================================

Xbool XVECTOR3::IsZero(Xvoid)
{
	return (this->X == 0 && this->Y == 0 && this->Z == 0);
}

//========================================================================

Xvoid XVECTOR3::Negate(Xvoid)
{
	this->X = -this->X;
	this->Y = -this->Y;
	this->Z = -this->Z;
}

//========================================================================

Xfloat XVECTOR3::Magnitude(Xvoid)
{
	return XMATH::Sqrt((this->X * this->X) + (this->Y * this->Y) + (this->Z * this->Z));
}

//========================================================================

Xfloat XVECTOR3::MagnitudeSQ(Xvoid)
{
	return (this->X * this->X) + (this->Y * this->Y) + (this->Z * this->Z);
}

//========================================================================

Xvoid XVECTOR3::Normalize(Xvoid)
{
	Xfloat Mag = this->Magnitude();
	if(Mag <= XMATH::EPSILON){Mag = 1;}
	this->X /= Mag;
	this->Y /= Mag;
	this->Z /= Mag;

	if(XMATH::FFabs(this->X) < XMATH::EPSILON){this->X = 0.0f;}
    if(XMATH::FFabs(this->Y) < XMATH::EPSILON){this->Y = 0.0f;}
	if(XMATH::FFabs(this->Z) < XMATH::EPSILON){this->Z = 0.0f;}
}

//========================================================================

Xvoid XVECTOR3::NormalizeEX(Xvoid)
{
	Xfloat Mag = 1 / this->Magnitude();
	this->X *= Mag;
	this->Y *= Mag;
	this->Z *= Mag;
}

//========================================================================

Xint XVECTOR3::Sign(Xvoid)
{
	return((this->X < XMATH::BGFLT) ? 4 : 0 | (this->X > XMATH::BGFLT) ? 32 : 0 | 
		   (this->Y < XMATH::BGFLT) ? 2 : 0 | (this->Y > XMATH::BGFLT) ? 16 : 0 | 
		   (this->Z < XMATH::BGFLT) ? 1 : 0 | (this->X > XMATH::BGFLT) ? 8 : 0);
}

//========================================================================

Xvoid XVECTOR3::CrossProduct(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	this->X = (Vector1->Y * Vector2->Z) - (Vector1->Z * Vector2->Y);
	this->Y = (Vector1->Z * Vector2->X) - (Vector1->X * Vector2->Z);
	this->Z = (Vector1->X * Vector2->Y) - (Vector1->Y * Vector2->X);
}

//========================================================================

Xvoid XVECTOR3::CrossProductEX(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	this->X =  (Vector1->Y * Vector2->Z) - (Vector1->Z * Vector2->Y);
	this->Y = -(Vector1->X * Vector2->Z) + (Vector1->Z * Vector2->X);
	this->Z =  (Vector1->X * Vector2->Y) - (Vector1->Y * Vector2->X);
}

//========================================================================

Xfloat XVECTOR3::ScalarProduct(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2, const XVECTOR3 *Vector3)
{
	return Xfloat((Vector1->X * (Vector2->Y * Vector3->Z - Vector2->Z * Vector3->Y)) +
		          (Vector1->Y * (Vector2->X * Vector3->Z - Vector2->Z * Vector3->X)) +
				  (Vector1->Z * (Vector2->X * Vector3->Y - Vector2->Y * Vector3->X)));
}

//========================================================================

Xvoid XVECTOR3::Power(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	this->X =  Vector1->Y * Vector2->Z - Vector1->Z * Vector2->Y;
	this->Y = -Vector1->X * Vector2->Z + Vector1->Z * Vector2->X; 
	this->Z =  Vector1->X * Vector2->Y - Vector1->Y * Vector2->X; 
}

//========================================================================

Xvoid XVECTOR3::Spherical(Xfloat Theta, Xfloat Rho, Xfloat Phi)
{
	this->X = (Phi * XMATH::Cos(Rho) * XMATH::Sin(Theta));
	this->Y = (Phi * XMATH::Sin(Rho));
	this->Z = (Phi * XMATH::Cos(Rho) * XMATH::Cos(Theta));
}

//========================================================================

Xvoid XVECTOR3::Scale(XVECTOR3 *retVector, const XVECTOR3 *Vector, Xfloat Scalar)
{
	retVector->X = Vector->X * Scalar;
	retVector->Y = Vector->Y * Scalar;
	retVector->Z = Vector->Z * Scalar;
}

//========================================================================

Xvoid XVECTOR3::Minimize(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	this->X = XMATH::Min(Vector1->X, Vector2->X);
    this->Y = XMATH::Min(Vector1->Y, Vector2->Y);
	this->Z = XMATH::Min(Vector1->Z, Vector2->Z);
}

//========================================================================

Xvoid XVECTOR3::Maximize(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	this->X = XMATH::Max(Vector1->X, Vector2->X);
    this->Y = XMATH::Max(Vector1->Y, Vector2->Y);
	this->Z = XMATH::Max(Vector1->Z, Vector2->Z);
}

//========================================================================

Xfloat XVECTOR3::Distance(const XVECTOR3 *Vector)
{
	return XMATH::Sqrt((Vector->X - this->X) * (Vector->X - this->X) + (Vector->Y - this->Y) * (Vector->Y - this->Y) + (Vector->Z - this->Z) * (Vector->Z - this->Z));
}

//========================================================================

Xfloat XVECTOR3::DistanceEX(const XVECTOR3 *Vector1, const XVECTOR3 *Vector2)
{
	XVECTOR3 Distance; Distance.Subtract(Vector2, Vector1);
	return Distance.Magnitude();
}

//========================================================================

Xbool XVECTOR3::NearlyEqual(const XVECTOR3 *Vector)
{
	if(XMATH::FFabs(this->X - Vector->X) < XMATH::EPSILON)
	{
		if(XMATH::FFabs(this->Y - Vector->Y) < XMATH::EPSILON)
		{
			if(XMATH::FFabs(this->Z - Vector->Z) < XMATH::EPSILON)
			{
				return Xtrue;
			}
		}
	}
	return Xfalse;
}
