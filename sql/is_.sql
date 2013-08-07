CREATE OR REPLACE FUNCTION is_(f boolean) RETURNS integer AS $$
        BEGIN
	 RETURN	case when f THEN 1 ELSE 0 END;
        END;
$$ LANGUAGE plpgsql;
