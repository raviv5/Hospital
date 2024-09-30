#include "SurgeryVisit.h"
#include"Surgeon.h"

//----------------------------------------------------------------------------//
SurgeryVisit::SurgeryVisit(const VisitCard& base, unsigned int p_room_num, bool p_fasting) :VisitCard(base)
{
	setRoomNumber(p_room_num);
	setFastStatus(p_fasting);
	if (m_room_num <= 0)
	{
		throw - 1;
	}
	Doctor* d = base.getDoctor();
	Surgeon* temp = dynamic_cast<Surgeon*>(d);
	temp->addToSurgeriesNum(1);

}
//----------------------------------------------------------------------------//
SurgeryVisit::SurgeryVisit(VisitCard&& base, unsigned int p_room_num, bool p_fasting) :VisitCard(std::move(base))
{
	setRoomNumber(p_room_num);
	setFastStatus(p_fasting);
	Doctor* d = base.getDoctor();
	Surgeon* temp = dynamic_cast<Surgeon*>(d);
	temp->addToSurgeriesNum(1);
}
//----------------------------------------------------------------------------//
SurgeryVisit::~SurgeryVisit()
{

}
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
unsigned int SurgeryVisit::getNumRoom()            const
{
	return m_room_num;
}
//----------------------------------------------------------------------------//
bool SurgeryVisit::getFastingstatus()              const
{
	return m_fasting;
}
//----------------------------------------------------------------------------//
void SurgeryVisit::setRoomNumber(unsigned int p_room_num)
{
	m_room_num = p_room_num;
}
//----------------------------------------------------------------------------//
void SurgeryVisit::setFastStatus(bool p_fasting)
{
	m_fasting = p_fasting;
}
//----------------------------------------------------------------------------//