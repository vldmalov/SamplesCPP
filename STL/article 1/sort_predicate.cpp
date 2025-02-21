
class nearest_point_predicate {
public:
    nearest_point_predicate(const sqc_point& center_point)
    : m_center_point(center_point)
    {}
    
    bool operator() (const sqc_point& point1, const sqc_point& point2){
        return get_length(point1, m_center_point) < get_length(point2, m_center_point);
    }
    
protected:
    float get_length(const sqc_point& point1, const sqc_point& point2) const {
        return sqrt( pow(point1.x - point2.x, 2) +
                    pow(point1.y - point2.y, 2));
    }
    
private:
    const sqc_point m_center_point;
};
