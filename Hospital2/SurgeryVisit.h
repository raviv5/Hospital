#ifndef _SURGERY_VISIT_H
#define  _SURGERY_VISIT_H

#include "VisitCard.h"
#include <stdbool.h>

class SurgeryVisit : public VisitCard
{
public:

	SurgeryVisit(const VisitCard& base, unsigned int p_room_num, bool p_fasting) noexcept(false);
	SurgeryVisit(VisitCard&& base, unsigned int p_room_num, bool p_fasting);
	virtual ~SurgeryVisit();

	unsigned int getNumRoom()            const;
	bool getFastingstatus()              const;

	void setRoomNumber(unsigned int p_room_num);
	void setFastStatus(bool p_fasting);
	virtual void toOs(ostream& os) const override {
		os << "fasting status:" << (m_fasting == 0 ? "false" : "true") << endl <<
			"room number:" << m_room_num;
	}


private:
	unsigned int m_room_num;
	bool m_fasting;
};

#endif // !_SURGERY_VISIT_H

