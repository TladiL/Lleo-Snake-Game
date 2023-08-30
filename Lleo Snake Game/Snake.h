#pragma once

#include "DEFINITIONS.h"
#include "Location.h"
#include "Board.h"

namespace Sonar
{
	class Snake
	{
	private:
		class Segments
		{
		public:
			void InitHead(const Location& loc);
			void InitBody();
			void Follow(const Segments& next);
			void MoveBy(const Location& delta_loc);
			void Draw(Board& brd) const;
			const Location& GetLocation() const;
			
		private:
			Location loc;
		};

	public:
		Snake(const Location& loc);
		void MoveBy(const Location& delta_loc);
		Location GetNextHeadLocation(const Location& delta_loc) const;
		void Grow();
		void Draw(Board& brd) const;
		bool IsInTileExceptEnd(const Location& target) const;
		bool IsInTile(const Location& target) const;

	private:
		static constexpr int nSegmentsMax = 100;
		Segments segments[nSegmentsMax];
		int nSegments = 1;
	};
}