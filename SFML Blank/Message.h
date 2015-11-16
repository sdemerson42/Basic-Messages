#ifndef __MESSAGE__
#define __MESSAGE__

template<typename DType>
class Message
{
public:
	enum class MType { pcMove, pcIdle, pcUp, pcDown, pcLeft, pcRight, pcLocation, pcStep, animFrameChange, spawnDiamond, despawn };
	Message(const MType& type, const DType& data);
	~Message() { }
	MType m_type;
	DType m_data;
};

template<typename DType>
Message<DType>::Message(const MType& type, const DType& data) : m_type(type), m_data(data)
{
}

#endif